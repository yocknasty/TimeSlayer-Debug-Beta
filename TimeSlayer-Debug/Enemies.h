#pragma once
/*========================================================================================
ENEMIES HEADER
lists enemy classes and member functions
==========================================================================================*/

#include "header.h"
#include "character.h"


class Enemy : public Character
{
public:
	Enemy();
	Enemy(float moveSpeed, float size, sf::Color const &newColor);
	~Enemy();

	bool getlifeStatus() const;

	void setlifeStatus();//switches the life staus to true if dead
	
private:
	bool _isDead; //is true the enemy is dead
	
	sf::CircleShape _enemy;//replace with an image latter
	

};

