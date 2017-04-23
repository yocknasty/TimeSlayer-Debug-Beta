/*
Pretty messily written Character/Player classes. 
Forgot the intricacies of OOP, if someone could make it 
more elegant that would be fantastic
*/

#pragma once

#include "header.h"

//Default 'Character' abstract. Did I need to type abstract before it? Idunno
class Character 
{
public:
	Character();
	Character(sf::Vector2f size, sf::Color color);
	~Character();

	void drawTo(sf::RenderWindow &window) {
		window.draw(character);
	}

	void move(sf::Vector2f distance) {
		character.move(distance);
	}

	void setPos(sf::Vector2f newPos) {
		character.setPosition(newPos);
	}

	float getMoveSpeed();
	float getGravity();

	void setMoveSpeed(float ms);
	void setGrav(float gr);

	int retY();
	int retX();

	int maxJump();

private:
	float moveSpeed;
	float gravity;

	sf::RectangleShape character; //Replace this with an image eventually
	
};

//Main Player class; Inherits Character traits
class Player : public Character
{
public:
	Player();
	~Player();

	void moveMe(sf::Vector2f dist);
	void setPos(sf::Vector2f newPos);
	void drawMe(sf::RenderWindow &window);
	sf::Vector2f GetPos();
	float gms();
	float ggr();

	void setCharacter(Character p);
	void setJump(bool cool);
	bool isJump();
	
	int retY();
	int retX();

	Character getCharacter();

private:
	Character player;
	bool isJumping;
};