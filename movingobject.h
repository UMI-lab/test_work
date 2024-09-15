#pragma once
#include "common.h"

class MovingObject
{
public:
    MovingObject();
    virtual ~MovingObject() = default;

    void setColor(float r, float g, float b);
    Vec2 getPosition();
    virtual void setPosition(const Vec2 new_position);

    CollisionRectangle getCollisionRectangle();

    bool hasRectangleCollision(MovingObject &  object);

    virtual void drawCollisionRectangle();

    virtual void step(double dt) = 0;

    virtual MovingObjectType getObjectType();


protected:
    Vec2 _position;
    CollisionRectangle _collisionRectangle;
    Color _color;
    MovingObjectType _object_type;
    float _speed;

};

