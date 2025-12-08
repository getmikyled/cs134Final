#include "BeamableObject.h"

#include "Beam.h"
#include "GameManager.h"
#include "Player.h"

void BeamableObject::onUpdate(ofEventArgs& args)
{
    if (beamed)
    {
        transform.position += (ufoPosition - transform.position).getNormalized() * ofGetLastFrameTime() * 10;
    }
}


void BeamableObject::onCollisionTriggered(GameObject* argGameObject, ofVec3f normal)
{
    Beam* beam = dynamic_cast<Beam*>(argGameObject);
    if (beam != nullptr)
    {
        beamed = true;
        ufoPosition = argGameObject->transform.position;
    }

   if (beamed)
   {
       Player* player = dynamic_cast<Player*>(argGameObject);
       if (player != nullptr)
       {
           pickupSound.play();
           pendingDestroy = true;
           GameManager::getInstance().addScore(5);
       }
   }
}

void BeamableObject::onDisable()
{
    GameObject::onDisable();
    pendingDestroy = true;
}
