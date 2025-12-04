#include "Beam.h"

void Beam::onUpdate(ofEventArgs& args)
{
    GameObject::onUpdate(args);

    light->setPosition(transform.position - ofVec3f(0, -5, 0));
}
