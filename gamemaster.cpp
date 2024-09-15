#include "gamemaster.h"

#include "player.h"
#include "bird.h"
#include "bomber.h"
#include "fighter.h"
#include "bulletfactory.h"


GameMaster::GameMaster()
{
    _player = std::make_shared<Player>();
    birds.push_back(std::make_shared<Bird>());
    time = 0.0;
    _bulletFactory = std::make_shared<BulletFactory>();
}

bool GameMaster::collisionDetection()
{
    for (auto & bird : birds)
    {
        if (bird->getPosition().x < 0.0)
        {
            birds.remove(bird);
            break;
        }
        if(_player->hasRectangleCollision(*bird))
        {
            //bird.reset();
            birds.remove(bird);
            std::cout << "Collision Bird" << std::endl;
            is_game = false;
            break;
        }

    }

    for (auto & bomber : bombers)
    {
        if (bomber->getPosition().x < 0.0)
        {
            bombers.remove(bomber);
            break;
        }
        if(_player->hasRectangleCollision(*bomber))
        {
            bomber.reset();
            bombers.remove(bomber);
            std::cout << "Collision Bomber" << std::endl;
            is_game = false;
            break;
        }
    }

    for (auto & fighter : fighters)
    {
        if (fighter->getPosition().x < 0.0)
        {
            fighters.remove(fighter);
            break;
        }
        if(_player->hasRectangleCollision(*fighter))
        {
            fighter.reset();
            fighters.remove(fighter);
            std::cout << "Collision Fighter" << std::endl;
            is_game = false;
            break;
        }
    }

    _bulletFactory->collisionDetection(bombers);
    _bulletFactory->collisionDetection(fighters);
    _bulletFactory->playerCollisionDetection(_player);

    return false;
}

void GameMaster::step(double dt)
{
    if(!is_game)
    {
        return;
    }

    if (std::abs(birds_timeout - fmod(time, birds_timeout)) < 0.1 && timeout > 1.0)
    {
        birds.push_back(std::make_shared<Bird>());
        timeout = 0.0;
    }
    if (std::abs(bombers_timeout - fmod(time, bombers_timeout)) < 0.1 && timeout > 1.0)
    {
        bombers.push_back(std::make_shared<Bomber>());
        timeout = 0.0;
    }

    if (std::abs(fighters_timeout - fmod(time, fighters_timeout)) < 0.1 && timeout > 1.0)
    {
        fighters.push_back(std::make_shared<Fighter>(_player, _bulletFactory));
        timeout = 0.0;
    }

    timeout += dt;
    _player->setPosition({mouseX, mouseY});
    _player->step(dt);
    for (auto & bird : birds)
    {
        bird->step(dt);
    }

    for (auto & bomber : bombers)
    {
        bomber->step(dt);
    }



    _bulletFactory->step(dt);

    for (auto & fighter : fighters)
    {
        fighter->step(dt);
    }


    _player->drawCollisionRectangle();
    collisionDetection();

    if(_bulletFactory->isPlayerDead())
    {
        is_game = false;
    }

    time += dt;


}

void GameMaster::setWidth(GLint new_width)
{
    width = new_width;
}

GLint GameMaster::getWidth()
{
    return width;
}

void GameMaster::setHeight(GLint new_height)
{
    height = new_height;
}

GLint GameMaster::getHeight()
{
    return height;
}

void GameMaster::setMousePos(GLfloat x, GLfloat y)
{
    mouseX = x;
    mouseY = y;
}

void GameMaster::playerShoot()
{
    _bulletFactory->createBullet(_player->getPosition(), Direction::RIGHT);
}

void GameMaster::startGame()
{
    is_game = true;
    birds.clear();
    bombers.clear();
    fighters.clear();
    time = 0.0;
    _bulletFactory->clearBullets();
}

bool GameMaster::getGameStatus()
{
    return is_game;
}

int GameMaster::getKills()
{
    return _bulletFactory->getEnemyKills();
}
