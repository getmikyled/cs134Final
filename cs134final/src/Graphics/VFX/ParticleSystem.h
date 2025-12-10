/*#pragma once
#include "Graphics\VFX\Particle.h"
#include "ofMain.h"
#include "Engine/Physics/Forces.h"

class ParticleSystem
{
    public:
    ParticleSystem();

    void add(const Particle &);
    void addForce(Force *);
    void remove(int);
    virtual void update();
    void setLifespan(float);
    void reset();
    
    //int removeNear(const ofVec3f & point, float dist);
    
    void draw();
    vector<Particle> particles;
    vector<Force *> forces;
    
};


class ExplosionVFX : ParticleSystem
{

    ExplosionVFX()
    {
        
    }
    float particleMagnitude = 5;
    float particleLifespan = 2;
};


class ParticleForce : public Force
{
    public:
    ParticleForce();
};


class ImpulseRadialForce : public ParticleForce {
    float magnitude;
    float height = .2;
public:
    void set(float mag) { magnitude = mag; }
    void setHeight(float h) { height = h; }
    ImpulseRadialForce(float magnitude);
    void updateForce(Particle *);
};*/