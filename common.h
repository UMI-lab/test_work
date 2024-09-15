#pragma once
#include <cstdlib>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <random>

struct Vec2
{
    Vec2(){
        x = 0.0;
        y = 0.0;
    }
    Vec2(float new_x, float new_y)
    {
        x = new_x;
        y = new_y;
    }
    float x;
    float y;
};

struct CollisionRectangle
{
    Vec2 center;
    float width;
    float height;
};

struct Color
{
    float r;
    float g;
    float b;
};

enum Direction
{
    LEFT,
    RIGHT
};

enum MovingObjectType
{
    NON_TYPE,
    PLAYER,
    BIRD,
    BOMBER,
    FIGHTER,
    BULLET
};

struct MathMethods
{
    static int sign(float a) {
        if (a > 0) return 1;
        else if (std::abs(a) < 0.01) return 0;
        else return -1;
    }
    static GLfloat RandomFloat(GLfloat a, GLfloat b) {
        std::random_device rd; // Случайный генератор
        std::mt19937 gen(rd()); // МТ19937 PRNG
        std::uniform_real_distribution<> dis(a, b); // Равномерное распределение на отрезке [a, b]

        return dis(gen);
    }

    static GLint RandomInt(GLint a, GLint b) {
        std::random_device rd; // Случайный генератор
        std::mt19937 gen(rd()); // МТ19937 PRNG
        std::uniform_int_distribution<> dis(a, b); // Равномерное распределение на отрезке [a, b]

        return dis(gen);
    }
};


