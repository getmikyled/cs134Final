#pragma once
#include "Engine/Core/GameObject.h"
#include "Engine/Core/Component.h"
#include "Graphics/VFX/Particle.h"
#include "ofMain.h"
#include "Engine/Physics/Forces.h"




class ParticleForce : public Force
{
public:
    ParticleForce() : Force() {}

    virtual void updateForce(Particle* particle) {}
};


class ParticleSystem : public Component
{
public:
    ParticleSystem() {}
    virtual ~ParticleSystem() {}

    void add(const Particle &);
    void addForce(ParticleForce *);
    void remove(int);
    void update() override;
    void reset();
    virtual void spawn(float time)
    {
        
    }
    
    void draw() override;
    vector<Particle> particles;
    vector<ParticleForce *> forces;
    
};







class ImpulseRadialForce : public ParticleForce {
    
public:
    ImpulseRadialForce()
    {
        magnitude = 10;
    }
    
    float height = .2;
    
    void set(float mag) { magnitude = mag; }
    void setHeight(float h) { height = h; }
    ImpulseRadialForce(float speed);
    void updateForce(Particle *) override;
};

class ExplosionVFX : public ParticleSystem
{
public:
    ExplosionVFX()
    {
        ImpulseRadialForce* force = new ImpulseRadialForce();
        force->indefinite = false;
        force->magnitude = particleMagnitude;
        forces.push_back(force);
        for (int i = 0; i < numParticles; i++)
        {
            spawn(ofGetElapsedTimeMillis());
        }
    }

    void spawn(float time) override;
    
    float particleMagnitude = 5;
    float particleLifespan = 10;
    int numParticles = 30;
};