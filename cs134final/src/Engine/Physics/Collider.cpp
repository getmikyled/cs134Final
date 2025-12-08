#include "Collider.h"

#include "GameObject.h"

void Collider::update()
{
    Component::update();
    
    collidedObjects.clear();
}


Box Collider::getBounds()
{
    // Return bounds of model if it exists
    if (model != nullptr)
    {
        glm::mat4x4 transform = gameObject->transform.getTransform();
        glm::vec3 min = transform * glm::vec4(model->model->getSceneMin() + model->model->getPosition(), 1.0f);
        glm::vec3 max = transform * glm::vec4(model->model->getSceneMax() + model->model->getPosition(), 1.0f);



        /*glm::mat4x4 transform = gameObject->transform.getTransform();

        std::vector<glm::vec3> vertices = model->mesh.getVertices();
        glm::vec3 min = glm::vec3(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
        glm::vec3 max = glm::vec3(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
        
        for (glm::vec3 vertex : vertices)
        {
            vertex = transform * glm::vec4(vertex, 1.0f);
            min.x=std::min(min.x, vertex.x);
            max.x=std::max(max.x, vertex.x);
            min.y=std::min(min.y, vertex.y);
            max.y=std::max(max.y, vertex.y);
            min.z=std::min(min.z, vertex.z);
            max.z=std::max(max.z, vertex.z); 
            
        }
        */


        
        return Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
    }

    return *manualBounds;
}
