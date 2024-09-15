#pragma once
#include "movingobject.h"

class Bomber : public MovingObject
{
public:
    Bomber();
    ~Bomber();

    void setPosition(const Vec2 new_position) override;
    void step(double dt) override;

private:
    bool _status;
};


