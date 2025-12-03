#include "Collider.h"

void Collider::initializeBounds(Model* model)
{
    ofVec3f min = model->model->getSceneMin() + model->model->getPosition();
    ofVec3f max = model->model->getSceneMax() + model->model->getPosition();
    bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
}
