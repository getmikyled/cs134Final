
//--------------------------------------------------------------
//
//  Kevin M. Smith
//
//  Simple Octree Implementation 11/10/2020
// 
//  Copyright (c) by Kevin M. Smith
//  Copying or use without permission is prohibited by law. 
//


#include "Octree.h"

 


//draw a box from a "Box" class  
//
void Octree::drawBox(const Box &box) {
	ofNoFill();
	Vector3 min = box.parameters[0];
	Vector3 max = box.parameters[1];
	Vector3 size = max - min;
	Vector3 center = size / 2 + min;
	ofVec3f p = ofVec3f(center.x(), center.y(), center.z());
	float w = size.x();
	float h = size.y();
	float d = size.z();
	ofDrawBox(p, w, h, d);
}

// return a Mesh Bounding Box for the entire Mesh
//
Box Octree::meshBounds(const ofMesh & mesh) {
	
	int n = mesh.getNumVertices();
	ofVec3f v = mesh.getVertex(0);
	ofVec3f max = v;
	ofVec3f min = v;
	for (int i = 1; i < n; i++) {
		ofVec3f v = mesh.getVertex(i);

		if (v.x > max.x) max.x = v.x;
		else if (v.x < min.x) min.x = v.x;

		if (v.y > max.y) max.y = v.y;
		else if (v.y < min.y) min.y = v.y;

		if (v.z > max.z) max.z = v.z;
		else if (v.z < min.z) min.z = v.z;
	}
	cout << "vertices: " << n << endl;
//	cout << "min: " << min << "max: " << max << endl;
	return Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
}

// getMeshPointsInBox:  return an array of indices to points in mesh that are contained 
//                      inside the Box.  Return count of points found;
//
int Octree::getMeshPointsInBox(const ofMesh &mesh, const vector<int> & points, Box& box, vector<int>& pointsRtn)
{
	int count = 0;
	for (int i = 0; i < points.size(); i++) {
		
		ofVec3f v = mesh.getVertex(points[i]);
		if (box.inside(Vector3(v.x, v.y, v.z))) {
			count++;
			pointsRtn.push_back(points[i]);
		}
	}
	return count;
}

// getMeshFacesInBox:  return an array of indices to Faces in mesh that are contained 
//                      inside the Box.  Return count of faces found;
//
int Octree::getMeshFacesInBox(const ofMesh & mesh, const vector<int>& faces,
	Box & box, vector<int> & facesRtn)
{
	int count = 0;
	for (int i = 0; i < faces.size(); i++) {
		ofMeshFace face = mesh.getFace(faces[i]);
		ofVec3f v[3];
		v[0] = face.getVertex(0);
		v[1] = face.getVertex(1);
		v[2] = face.getVertex(2);
		Vector3 p[3];
		p[0] = Vector3(v[0].x, v[0].y, v[0].z);
		p[1] = Vector3(v[1].x, v[1].y, v[1].z);
		p[2] = Vector3(v[2].x, v[2].y, v[2].z);
		if (box.inside(p,3)) {
			count++;
			facesRtn.push_back(faces[i]);
		}
	}
	return count;
}

//  Subdivide a Box into eight(8) equal size boxes, return them in boxList;
//
void Octree::subDivideBox8(const Box &box, vector<Box> & boxList) {
	Vector3 min = box.parameters[0];
	Vector3 max = box.parameters[1];
	Vector3 size = max - min;
	Vector3 center = size / 2 + min;
	float xdist = (max.x() - min.x()) / 2;
	float ydist = (max.y() - min.y()) / 2;
	float zdist = (max.z() - min.z()) / 2;
	Vector3 h = Vector3(0, ydist, 0);

	//  generate ground floor
	//
	Box b[8];
	b[0] = Box(min, center);
	b[1] = Box(b[0].min() + Vector3(xdist, 0, 0), b[0].max() + Vector3(xdist, 0, 0));
	b[2] = Box(b[1].min() + Vector3(0, 0, zdist), b[1].max() + Vector3(0, 0, zdist));
	b[3] = Box(b[2].min() + Vector3(-xdist, 0, 0), b[2].max() + Vector3(-xdist, 0, 0));

	boxList.clear();
	for (int i = 0; i < 4; i++)
		boxList.push_back(b[i]);

	// generate second story
	//
	for (int i = 4; i < 8; i++) {
		b[i] = Box(b[i - 4].min() + h, b[i - 4].max() + h);
		boxList.push_back(b[i]);
	}
}

void Octree::create(int numLevels) {
	// initialize octree structure
	//
	int level = 0;

	// Set root box to the largest bounding box given all static meshes
	cout << "Starting to set mesh bounds" << endl;
	
	root.box = meshBounds(staticMeshes[0]->mesh);
	cout << "Set initial mesh bounds" << endl;
	for (int i = 1; i < staticMeshes.size(); i++)
	{
		Box tempBox = meshBounds(staticMeshes[i]->mesh);
		root.box.parameters[0] = min(tempBox.parameters[0], root.box.parameters[0]);
		root.box.parameters[1] = max(tempBox.parameters[1], root.box.parameters[1]);
	}
	cout << "Finished setting mesh bounds" << endl;

	// Add points from all meshes
	

	for (int i = 0; i < staticMeshes.size(); i++)
	{
		vector<int> points;
		int numVertices = staticMeshes[i]->mesh.getNumVertices();
		
		for (int j = 0; j < numVertices; j++)
		{
			points.push_back(j);
		}

		root.points.push_back(points);
	}

	cout << "Finished adding points to root" << endl;

	// recursively buid octree
	//
	level++;
    subdivide(root, numLevels, level);
}


//
// subdivide:  recursive function to perform octree subdivision on a mesh
//
//  subdivide(node) algorithm:
//     1) subdivide box in node into 8 equal side boxes - see helper function subDivideBox8().
//     2) For each child box
//            sort point data into each box  (see helper function getMeshFacesInBox())
//        if a child box contains at list 1 point
//            add child to tree
//            if child is not a leaf node (contains more than 1 point)
//               recursively call subdivide(child)
//         
//      
             
void Octree::subdivide(TreeNode & node, int numLevels, int level)
	{
	if (level >= numLevels) return;
	cout << level << " ";
	std::vector<Box> boxlist;
	subDivideBox8(node.box, boxlist);
	
	for (int i = 0; i < boxlist.size(); i++) {

		int index = node.children.size();
		int pointCount = 0;

		std::vector<vector<int>> pointsInBox;
		
		for (int j = 0; j < staticMeshes.size(); j++)
		{
			
			ofMesh meshModel = staticMeshes[j]->mesh;

			vector<int> points;
			getMeshPointsInBox(meshModel, node.points[j], boxlist[i], points);
			pointCount += points.size();
			pointsInBox.push_back(points);
		}

		if (pointCount > 5)
		{
			TreeNode newTreeNode;
			
			node.children.push_back(newTreeNode);
			node.children[index].box = boxlist[i];
			node.children[index].points = pointsInBox;
			subdivide(node.children[index], numLevels, level + 1);
		}

		
					
		
	}
}



bool Octree::intersect(const Ray &ray, const TreeNode & node, TreeNode & nodeRtn) {
	float tnear = -std::numeric_limits<float>::infinity();
	float tfar = std::numeric_limits<float>::infinity();

	Box box = node.box;
	Vector3 min = box.min();
	Vector3 max = box.max();

	// if ray is parallel & origin is not inside bounding box
	for (int i = 0; i < 3; i++) {
		if (ray.direction[i] == 0 && (ray.origin[i] < min[i] || ray.origin[i] > max[i])) return false;
	}
	
	// iterate over x y z to test ray collision
	for (int i = 0; i < 3; i++) {
		float t1 = (min[i] - ray.origin[i]) / ray.direction[i];
		float t2 = (max[i] - ray.origin[i]) / ray.direction[i];

		if (t1 > t2) {
			// swap t2 and t1
			float temp;
			temp = t1;
			t1 = t2;
			t2 = temp;
		}

		if (t1 > tnear) tnear = t1;
		if (t2 < tfar) tfar = t2;

		if (tnear > tfar || tfar < 0) return false;
	}


	if (node.children.empty()) {
		nodeRtn = node;
		return true;
	}
	else {
		for (int i = 0; i < node.children.size(); i++) {
			if (intersect(ray, node.children[i], nodeRtn)) {
				return true;
			}
		}
		return false;
	}

	

	
}

bool Octree::intersect(Box &box, TreeNode & node, vector<Box> & boxListRtn) {
	if (!node.box.overlap(box)) return false;

	bool intersected = false;

	if (node.children.empty()) {
		boxListRtn.push_back(node.box);
		return true;
	}
	else {
		for (int i = 0; i < node.children.size(); i++) {
			if(intersect(box, node.children[i], boxListRtn)) intersected = true;
		}
		return intersected;
	}
	
	
}

void Octree::draw()
{
	GameObject::draw();

	draw(root, 20, 1);
}


void Octree::draw(TreeNode & node, int numLevels, int level) {
	if (level >= numLevels) return;

	glm::vec3 color = glm::vec3(0, 0, 255);
	color.x = 0 + (float(level + 1) / float(numLevels)) * (255 - 0);
	ofSetColor(color.x, color.y, color.z);
	drawBox(node.box);

	for (int i = 0; i < node.children.size(); i++) {
		draw(node.children[i], numLevels, level + 1);
	}
	
}



