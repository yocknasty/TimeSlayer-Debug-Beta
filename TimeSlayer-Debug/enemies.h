#pragma once
#include "header.h"
#include "character.h"
//holds the code for enemy characters
class Enemy : public Character
{
public:
	Enemy();
	Enemy(int index);
	~Enemy();
	int getIndex();
	bool getDead();


	void setEnemy(Character e);
	void moveEnemy(sf::Vector2f dist);
	void setPos(sf::Vector2f newPos);
	void drawEnemy(sf::RenderWindow &window);
private:
	int enemy_Index; //tells which enemy is in the array
	bool is_dead;
	Character _evilguy;

};

