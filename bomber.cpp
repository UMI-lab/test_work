#include "bomber.h"

Bomber::Bomber()
    : MovingObject()
{
    _position = {1.0, MathMethods::RandomFloat(0.33f, 1.0f)};
    std::cout << _position.y << std::endl;;
    _collisionRectangle.center = _position;
    _collisionRectangle.height = 0.05;
    _collisionRectangle.width = 0.07;
    _color = {1.0, 0.0, 0.0};

    if (_position.y > 0.66f)
    {
        _speed = 0.3;
    } else {
        _speed = 0.2;
    }

    _status = true;
    _object_type = MovingObjectType::BOMBER;
}

Bomber::~Bomber()
{
    std::cout << "Bomber out" << std::endl;
}

void Bomber::setPosition(const Vec2 new_position)
{
    _position = new_position;

    _collisionRectangle.center = _position;
}

void Bomber::step(double dt)
{
    if (_status)
    {
        _position.x -= _speed*dt;
        setPosition(_position);

        drawCollisionRectangle();
    }
    if (_position.x < 0.0)
    {
        _status = false;
    }
}
