#pragma once

#include <list>
#include "common.h"

class Bird;
class Bomber;
class Fighter;
class Player;
class BulletFactory;

class GameMaster
{
public:
    GameMaster();
    ~GameMaster() = default;

    bool collisionDetection();

    void step(double dt);

    void setWidth(GLint new_width);

    GLint getWidth();

    void setHeight(GLint new_height);

    GLint getHeight();

    void setMousePos(GLfloat x, GLfloat y);

    void playerShoot();

    void startGame();

    bool getGameStatus();

    int getKills();

private:
    GLfloat mouseX;
    GLfloat mouseY;
    GLint width;
    GLint height;

    std::shared_ptr<Player> _player;
    std::shared_ptr<BulletFactory> _bulletFactory;

    std::list<std::shared_ptr<Bird>> birds;
    std::list<std::shared_ptr<Bomber>> bombers;
    std::list<std::shared_ptr<Fighter>> fighters;

    double timeout = 0.0;

    double time;
    double birds_timeout = 5.0;
    double bombers_timeout = 9.0;
    double fighters_timeout = 3.0;

    bool is_game = false;
};
