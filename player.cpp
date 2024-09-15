#include "player.h"

Player::Player()
    : MovingObject()
{
    _position = {0.0, 0.0};
    _collisionRectangle.center = _position;
    _collisionRectangle.height = 0.05;
    _collisionRectangle.width = 0.05;
    _color = {1.0, 1.0, 1.0};
    _speed = 0.2;
    _object_type = MovingObjectType::PLAYER;
}

void Player::setPosition(const Vec2 new_position)
{
    _mouse_position = new_position;
}

void Player::step(double dt)
{
    _position.x += (MathMethods::sign(_mouse_position.x -_position.x) * _speed * dt);
    _position.y += (MathMethods::sign(_mouse_position.y -_position.y) * _speed * dt);
    if(_position.x > 0.33)
    {
        _position.x = 0.33;
    }
    _collisionRectangle.center = _position = _position;
}
