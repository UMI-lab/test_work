#pragma once

#include "movingobject.h"

class Bullet : public MovingObject
{
public:
    Bullet(Vec2 pos, Direction direction);
    ~Bullet();

    void setPosition(const Vec2 new_position) override;
    void step(double dt) override;

private:
    bool _status;
    Direction _direction;
};
