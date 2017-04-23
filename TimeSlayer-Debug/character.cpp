/*
Any functions related to characters should go in here.

*/

#include "character.h"

//----Getters----
//Gets the character's movespeed
float Character::getMoveSpeed(){
	return moveSpeed;
}

//Gets the character's gravity
float Character::getGravity(){
	return gravity;
}

Character Player::getCharacter() {
	return player;

}


//----Setters----
//Sets the character's move speed
void Character::setMoveSpeed(float ms){
	moveSpeed = ms;
}

//Sets the characters gravity
void Character::setGrav(float gr){
	gravity = gr;
}

//Sets the Player character type
void Player::setCharacter(Character p) {
	player = p;
	player.setMoveSpeed(0.2);
	player.setGrav(0.3);
	isJumping = false;
}

void Player::setPos(sf::Vector2f newPos) {
	player.setPos(newPos);
}

sf::Vector2f Player::GetPos()
{
	sf::Vector2f Position;
	Position.x = player.retX();
	Position.y = player.retY();
	return Position;
}

//----Constructors & Destructors----
Player::Player() {
	//default character constructor makes a 20x20 black square
	player = Character({20,20},sf::Color::Black);
	
}

Player::~Player() {

}

Character::Character() {
	character.setSize({ 20,20 });
	character.setFillColor(sf::Color::Black);
}

Character::Character(sf::Vector2f size, sf::Color color) {
	character.setSize(size);
	character.setFillColor(color);
}

Character::~Character(){

}


//----Other Functions----
void Player::moveMe(sf::Vector2f dist) {
	player.move(dist);
}

void Player::drawMe(sf::RenderWindow &window) {
	player.drawTo(window);
}

float Player::gms() {
	return player.getMoveSpeed();
}

float Player::ggr() {
	return player.getGravity();
}

void Player::setJump(bool cool) {
	isJumping = cool;
}

int Character::retY() {
	return character.getPosition().y;
}

int Character::retX() {
	return character.getPosition().x;
}

int Player::retY() {
	return player.retY();
}

int Player::retX() {
	return player.retX();
}

bool Player::isJump() {
	return isJumping;
}

int Character::maxJump() {
	return character.getPosition().y - 100;
}