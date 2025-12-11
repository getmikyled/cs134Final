#include "Graphics\VFX\Particle.h"

Particle::Particle() {

    // initialize particle with some reasonable values first;
    //
    velocity.set(0, 0, 0);
    acceleration.set(0, 0, 0);
    position.set(0, 0, 0);
    forces.set(0, 0, 0);
    lifespan = 5;
    birthtime = 0;
    radius = .1;
    damping = .97;
    mass = 1;
    color = ofColor::aquamarine;
    alpha = 1;

    colors.emplace_back(ofColor(255, 117, 31, 255)); //bright orange
    colors.emplace_back(ofColor(181, 20, 66, 200));
    colors.emplace_back(ofColor(61, 47, 84, 100));
    colors.emplace_back(ofColor(33, 33, 33, 0));
    
}

void Particle::draw() {
    //	ofSetColor(color);
    
    //ofSetColor(ofMap(normalizedAge(), 0, 1, 255, 10), 0, 0);
    radius = radiusmax * (1 - normalizedAge());
    ofFill();
    float lerpval = normalizedAge() * (colors.size()-1); // range from 0-3
    int key = floor(lerpval); // 0 1 or 2

    if (key >= colors.size()-1) key = colors.size() - 2; // if key >= 3, set key to 2
    lerpval -= float(key);
    ofSetColor(colors[key].lerp(colors[key+1], lerpval));
    cout << colors[key].lerp(colors[key+1], lerpval) << endl;
    
    
    ofDrawSphere(position, radius);
}


void Particle::integrate() {


    float dt = ofGetLastFrameTime();

    position += (velocity * dt);

    ofVec3f accel = acceleration;   
    accel += (forces * (1.0 / mass));
    velocity += accel * dt;
    velocity *= damping;


    forces.set(0, 0, 0);
}


float Particle::normalizedAge() {
    return ((ofGetElapsedTimeMillis() - birthtime)/1000.0)/lifespan;
}

