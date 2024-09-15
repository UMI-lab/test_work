#include "bird.h"

Bird::Bird()
    : MovingObject()
{
    _position = {1.0, MathMethods::RandomFloat(0.33f, 0.0f)};
    _collisionRectangle.center = _position;
    _collisionRectangle.height = 0.03;
    _collisionRectangle.width = 0.03;
    _color = {0.0, 1.0, 0.0};
    _speed = 0.1;
    _status = true;
    _object_type = MovingObjectType::BIRD;
}

Bird::~Bird()
{
    std::cout << "Bird out" << std::endl;
}


void Bird::setPosition(const Vec2 new_position)
{
    _position = new_position;

    _collisionRectangle.center = _position;
}

void Bird::step(double dt)
{
    if (_status)
    {
        _position.x -= _speed*dt;
        _position.y += MathMethods::RandomInt(-1, 1) * _speed*dt;
        setPosition(_position);

        drawCollisionRectangle();
    }
    if (_position.x < 0.0)
    {
        _status = false;
    }
}
