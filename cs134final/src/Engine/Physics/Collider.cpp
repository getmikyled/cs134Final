#include "Collider.h"

#include "GameObject.h"

void Collider::update()
{
    Component::update();
    
    collidedObjects.clear();
}


Box Collider::getBounds()
{
    glm::mat4x4 transform = gameObject->transform.getTransform();
    glm::vec3 min = transform * glm::vec4(model->model->getSceneMin() + model->model->getPosition(), 1.0f);
    glm::vec3 max = transform * glm::vec4(model->model->getSceneMax() + model->model->getPosition(), 1.0f);
    return Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
}
