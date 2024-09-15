#pragma once
#include <list>
#include <memory>
#include "common.h"
#include "bullet.h"
#include "player.h"


class Player;
class Bullet;

class BulletFactory
{
public:
    BulletFactory();;

    void createBullet(Vec2 position, Direction direction);
    void playerCollisionDetection(std::shared_ptr<Player> & player);

    template<typename Object>
    void collisionDetection(std::list<std::shared_ptr<Object>> & objects)
    {
        MovingObjectType type;


        if (objects.empty())
        {
            return;
        } else {
            type = objects.front()->getObjectType();
        }

        if (type == MovingObjectType::BOMBER || type == MovingObjectType::FIGHTER)
        {
            bool is_bomber = true;
            for (auto & object : objects)
            {
                if (!is_bomber) break;

                for (auto & bullet : _players_bullets)
                {
                    if(object->hasRectangleCollision(*bullet))
                    {
                        std::cout << "Cpllision" << std:: endl;
                        objects.remove(object);
                        _players_bullets.remove(bullet);
                        is_bomber = false;
                        enemy_kills++;
                        break;
                    }
                }
            }
        }
    }

    void step(double dt);
    void clearBullets();
    int getEnemyKills();
    bool isPlayerDead();

private:
    std::list<std::unique_ptr<Bullet>> _players_bullets;
    std::list<std::unique_ptr<Bullet>> _enemy_bullets;
    int enemy_kills = 0;
    bool is_player_dead = false;
};

