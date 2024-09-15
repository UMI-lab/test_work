#pragma once

#include "movingobject.h"
#include "common.h"

class Player : public MovingObject
{
public:
    Player();
    ~Player() = default;

    void setPosition(const Vec2 new_position) override;
    void step(double dt) override;

private:
    Vec2 _mouse_position;

};


