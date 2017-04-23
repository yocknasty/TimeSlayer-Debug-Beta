#include "enemies.h"

//holds the code for enemy characters

//Enemy Code
Enemy::Enemy()
{
	is_dead = false;
	moveSpeed = -0.01;
	setGrav(0);
}
Enemy::Enemy(int index)
{
	enemy_Index = index;
	is_dead = false;
	moveSpeed = -0.01;
	setGrav(0);
}

Enemy::~Enemy()
{
}
void Enemy::moveEnemy(sf::Vector2f dist)
{
	_evilguy.move(dist);
}
void Enemy::setPos(sf::Vector2f newPos)
{
	_evilguy.setPos(newPos);
}
void Enemy::drawEnemy(sf::RenderWindow &window)
{
	_evilguy.drawTo(window);
}
void Enemy::setEnemy(Character e)
{
	_evilguy = e;
}
int Enemy::getIndex()
{
	return enemy_Index;
}
//returns true if enemy is dead
bool Enemy::getDead()
{
	return is_dead;
}