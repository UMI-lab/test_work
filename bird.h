#pragma once

#include "movingobject.h"

class Bird : public MovingObject
{
public:
    Bird();
    ~Bird();

    void setPosition(const Vec2 new_position) override;
    void step(double dt) override;

private:
    bool _status;
};
