#pragma once

class GameObject;

class Component
{
public:
    
    virtual void update() {}
    virtual void draw() {}

    GameObject* gameObject = nullptr;
};
