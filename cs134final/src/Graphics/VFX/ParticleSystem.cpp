/*#include "ParticleSystem.h"

void ParticleSystem::add(const Particle &p) {
    particles.push_back(p);
}

void ParticleSystem::addForce(Force *f) {
    forces.push_back(f);
}

void ParticleSystem::remove(int i) {
    particles.erase(particles.begin() + i);
}

void ParticleSystem::setLifespan(float l) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].lifespan = l;
    }
}

void ParticleSystem::reset() {
    for (int i = 0; i < forces.size(); i++) {
        //forces[i]->applied = false;
    }
}

void ParticleSystem::update() {
    if (particles.size() == 0) return;

    vector<Particle>::iterator p = particles.begin();
    vector<Particle>::iterator tmp;


    while (p != particles.end()) {
        if (p->lifespan != -1 && p->normalizedAge() > 1) {
            tmp = particles.erase(p);
            p = tmp;
        }
        else p++;
    }

    // update forces on all particles first 
    //
    for (int i = 0; i < particles.size(); i++) {
        for (int k = 0; k < forces.size(); k++) {
            //forces[k]->updateForce( &particles[i] );
        }
    }
    
    


    for (int i = 0; i < particles.size(); i++)
        particles[i].integrate();

    for (int i = 0; i < forces.size(); i++) {
        if (!forces[i]->indefinite)
            forces.erase(forces.begin() + i);
    }
}


void ParticleSystem::draw() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}


ImpulseRadialForce::ImpulseRadialForce(float magnitude) {
    this->magnitude = magnitude;
    indefinite = false;
}

void ImpulseRadialForce::updateForce(Particle * particle) {

    // we basically create a random direction for each particle
    // the force is only added once after it is triggered.
    //
    ofVec3f dir = ofVec3f(ofRandom(-1, 1), ofRandom(-height/2.0, height/2.0), ofRandom(-1, 1));
    particle->forces += dir.getNormalized() * ofRandom(magnitude-2, magnitude+2);
}*/