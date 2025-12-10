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

    virtual void initialize() {}
    
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
        
    }

    void spawn(float time) override;

    void initialize() override
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
    
    float particleMagnitude = 40;
    float particleLifespan = 2.5;
    float particleRadius = 1;
    int numParticles = 30;
};