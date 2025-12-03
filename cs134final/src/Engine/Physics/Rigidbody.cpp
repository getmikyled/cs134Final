#include "Rigidbody.h"

#include "GameObject.h"
#include "ofAppRunner.h"

void Rigidbody::update()
{
    collidedObjects.clear();

    integrate();
}

ofVec3f Rigidbody::calculateForces()
{
    ofVec3f result = ofVec3f(0, 0, 0);

    for (int i = forces.size() - 1; i >= 0; i--)
    {
        Force* force = forces[i];
        result += force->getForce();
    
        // Erase if force is NOT indefinite on the system
        if (force->indefinite == false)
        {
            forces.erase(forces.begin() + i);
        }
    }

    return result;
}

ofVec3f Rigidbody::calculateRotationalForces()
{
    ofVec3f result = ofVec3f(0, 0, 0);

    for (int i = forces.size() - 1; i >= 0; i--)
    {
        Force* force = forces[i];
        result += force->getForce();
    
        // Erase if force is NOT indefinite on the system
        if (force->indefinite == false)
        {
            forces.erase(forces.begin() + i);
        }
        
    }

    return result;
}


void Rigidbody::integrate()
{
    float frameRate = ofGetFrameRate();
    if (frameRate < 1.0f)
    {
        // Return if greater than 0 to prevent division by 0
        return;
    }
    float dt = 1.0f / frameRate;
    
    gameObject->transform.position += (velocity * dt);
    ofVec3f accel = acceleration;
    accel += calculateForces() * (1.0 / mass);
    velocity += accel * dt;
    velocity *= damping;

    if (velocity.length() > maxSpeed) velocity = velocity.normalize() * maxSpeed;
}