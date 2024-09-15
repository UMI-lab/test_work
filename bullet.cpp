#include "bullet.h"


Bullet::Bullet(Vec2 pos, Direction direction)
    : MovingObject()
{
    _position = pos;
    _collisionRectangle.center = _position;
    _collisionRectangle.height = 0.01;
    _collisionRectangle.width = 0.01;
    _color = {0.0, 1.0, 1.0};
    _speed = 0.5;
    _status = true;
    _direction = direction;
    _object_type = MovingObjectType::BULLET;
}

Bullet::~Bullet()
{
    std::cout << "Bullet out" << std::endl;
}

void Bullet::setPosition(const Vec2 new_position)
{
    _position = new_position;

    _collisionRectangle.center = _position;
}

void Bullet::step(double dt)
{
    if (_status)
    {
        switch (_direction) {
        case Direction::RIGHT:
            _position.x += _speed*dt;

            setPosition(_position);

            drawCollisionRectangle();
            if (_position.x > 1.0)
            {
                _status = false;
            }
            break;
        case Direction::LEFT:
            _position.x -= _speed*dt;

            setPosition(_position);

            drawCollisionRectangle();
            if (_position.x < 0.0)
            {
                _status = false;
            }
            break;
        default:
            break;
        }
    }

}
