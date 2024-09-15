#include "bulletfactory.h"

BulletFactory::BulletFactory(){}

void BulletFactory::createBullet(Vec2 position, Direction direction)
{
    switch (direction) {
    case Direction::RIGHT:
        _players_bullets.push_back(std::make_unique<Bullet>(position, direction));
        break;
    case Direction::LEFT:
        _enemy_bullets.push_back(std::make_unique<Bullet>(position, direction));
        break;
    default:
        break;
    }
}

void BulletFactory::playerCollisionDetection(std::shared_ptr<Player> &player)
{
    for (auto & bullet : _enemy_bullets)
    {
        if(player->hasRectangleCollision(*bullet))
        {
            _enemy_bullets.remove(bullet);
            is_player_dead = true;
            break;
        }
    }
}

void BulletFactory::step(double dt)
{
    for (auto & bullet : _players_bullets)
    {
        if (bullet->getPosition().x > 1.0)
        {
            _players_bullets.remove(bullet);
            break;
        }
    }

    for (auto & bullet : _enemy_bullets)
    {
        if (bullet->getPosition().x < 0.0)
        {
            _enemy_bullets.remove(bullet);
            break;
        }
    }

    for (auto & bullet : _players_bullets)
    {
        bullet->step(dt);
    }
    for (auto & bullet : _enemy_bullets)
    {
        bullet->step(dt);
    }
}

void BulletFactory::clearBullets() {
    _players_bullets.clear();
    _enemy_bullets.clear();
    enemy_kills = 0;
    is_player_dead = false;
}

int BulletFactory::getEnemyKills() {return enemy_kills;}

bool BulletFactory::isPlayerDead() {return is_player_dead;}
