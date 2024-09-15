#pragma once
#include "movingobject.h"


class BulletFactory;
class Player;

class Fighter : public MovingObject
{
public:
    Fighter(std::shared_ptr<Player> player, std::shared_ptr<BulletFactory> bullet_factory);
    ~Fighter();

    void setPlayer(std::shared_ptr<Player> player);


    void setPosition(const Vec2 new_position) override;
    void step(double dt) override;

private:
    bool _status;
    std::shared_ptr<Player> _player;
    double shoot_timeout = 0.0;
    double shoot_cooldown = 1;
    std::shared_ptr<BulletFactory> _bullet_factory;


};
