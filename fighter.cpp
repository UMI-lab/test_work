#include "fighter.h"

#include "player.h"
#include "bulletfactory.h"


Fighter::Fighter(std::shared_ptr<Player> player, std::shared_ptr<BulletFactory> bullet_factory)
    : MovingObject()
{
    _position = {1.0, MathMethods::RandomFloat(0.33f, 1.0f)};
    std::cout << _position.y << std::endl;;
    _collisionRectangle.center = _position;
    _collisionRectangle.height = 0.03;
    _collisionRectangle.width = 0.05;
    _color = {0.0, 0.0, 1.0};

    if (_position.y > 0.66f)
    {
        _speed = 0.3;
    } else {
        _speed = 0.2;
    }

    _status = true;
    setPlayer(player);
    _object_type = MovingObjectType::FIGHTER;
    _bullet_factory = bullet_factory;
}

Fighter::~Fighter()
{
    std::cout << "Fighter out" << std::endl;
}

void Fighter::setPlayer(std::shared_ptr<Player> player)
{
    _player = player;
}

void Fighter::setPosition(const Vec2 new_position)
{
    _position = new_position;

    _collisionRectangle.center = _position;
}

void Fighter::step(double dt)
{
    if (_status)
    {
        _position.x -= _speed*dt;
        _position.y += (MathMethods::sign(_player->getPosition().y -_position.y) * _speed * dt) / 5;
        setPosition(_position);

        drawCollisionRectangle();
    }
    if (_position.x < 0.0)
    {
        _status = false;
    }
    shoot_timeout += dt;
    if (shoot_timeout > shoot_cooldown && std::abs(_player->getPosition().y -_position.y) < 0.005)
    {
        _bullet_factory->createBullet(_position, Direction::LEFT);
        shoot_timeout = 0.0;
    }
}
