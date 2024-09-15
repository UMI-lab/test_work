#include "movingobject.h"


MovingObject::MovingObject()
{
    _position = {0.0, 0.0};
    _collisionRectangle = {_position, 0.1, 0.1};
    _object_type = MovingObjectType::NON_TYPE;

}

void MovingObject::setColor(float r, float g, float b)
{
    _color = {r, g, b};
}

Vec2 MovingObject::getPosition() {return _position;}

void MovingObject::setPosition(const Vec2 new_position)
{
    _position = new_position;
    _collisionRectangle.center = _position;
}

CollisionRectangle MovingObject::getCollisionRectangle() {return _collisionRectangle;}

bool MovingObject::hasRectangleCollision(MovingObject &object)
{
    CollisionRectangle  rectangle = object.getCollisionRectangle();
    if (_collisionRectangle.center.x < rectangle.center.x + rectangle.width &&
        _collisionRectangle.center.x + _collisionRectangle.width > rectangle.center.x &&
        _collisionRectangle.center.y < rectangle.center.y + rectangle.height &&
        _collisionRectangle.center.y + _collisionRectangle.height > rectangle.center.y)
    {
        return true;
    }
    return false;
}

void MovingObject::drawCollisionRectangle()
{
    glPushMatrix();
    glColor3f(_color.r, _color.g, _color.b);
    glBegin(GL_LINE_LOOP);
    glVertex3f( _collisionRectangle.center.x - _collisionRectangle.width / 2.0, _collisionRectangle.center.y + _collisionRectangle.height / 2.0, 0.0f);
    glVertex3f( _collisionRectangle.center.x + _collisionRectangle.width / 2.0, _collisionRectangle.center.y + _collisionRectangle.height / 2.0, 0.0f);
    glVertex3f( _collisionRectangle.center.x + _collisionRectangle.width / 2.0, _collisionRectangle.center.y - _collisionRectangle.height / 2.0, 0.0f);
    glVertex3f( _collisionRectangle.center.x - _collisionRectangle.width / 2.0, _collisionRectangle.center.y - _collisionRectangle.height / 2.0, 0.0f);
    glEnd();
    glPopMatrix();
}

MovingObjectType MovingObject::getObjectType() {return _object_type;}
