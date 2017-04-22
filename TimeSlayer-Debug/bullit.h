#pragma once
#include "header.h"

class Bullet : public sf::RectangleShape
{

public:

	bool shot;

	Bullet(const sf::Color & color = sf::Color::Black, const sf::Vector2f & size = sf::Vector2f(20, 10), sf::Vector2f & position = sf::Vector2f(300, 100))//default values 
	{
		this->setFillColor(color);
		this->setSize(size);
		this->setPosition(position);
		shot = false;
	}


};
