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
    damping = .99;
    mass = 1;
    color = ofColor::aquamarine;
    alpha = 1;
}

void Particle::draw() {
    //	ofSetColor(color);
    ofSetColor(ofMap(normalizedAge(), 0, lifespan, 255, 10), 0, 0);
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

