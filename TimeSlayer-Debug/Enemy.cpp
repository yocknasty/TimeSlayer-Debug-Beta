#include "Enemies.h"
//default constructor
Enemy::Enemy()
{
	_isDead = false;
	
}

Enemy::~Enemy()
{
}
//constructor for enemys
Enemy::Enemy(float enemySpeed, float size, sf::Color const &newColor)
{
	_isDead = false;
	moveSpeed = enemySpeed;
	_enemy.setFillColor(newColor);
	_enemy.setRadius(size);
}
//returns True if enemy is dead
bool Enemy::getlifeStatus() const
{
	return _isDead;
}

//switches the life staus to true if dead
void Enemy::setlifeStatus()
{
	if (_isDead)
	{
		_isDead= false;
	}
	else
	{
		_isDead = true;
	}
}
//switches the on screen status

