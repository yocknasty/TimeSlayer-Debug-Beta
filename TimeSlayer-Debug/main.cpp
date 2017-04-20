/* 
	I mean it's main.
	If you don't know what this is by now
	this is going to be a long project.
*/

#include "character.h"
#include "Enemies.h"
using std::endl;
using std::string;

int main() {

	//Generates the screen
	sf::Vector2i screenDimensions(800, 260);

	//Renders the Window
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "TimeSlayers");

	//Initially loads the background
	sf::Texture bTexture;
	if (!bTexture.loadFromFile("Background.png")) {
		return -1;
	}

	//Sets the background to the loaded image
	sf::Sprite bimage;
	bimage.setTexture(bTexture);

	//Generates the player
	Player kLlam;
	Enemy evilGuy(-0.1, 3, sf::Color::Blue);
	kLlam.setCharacter(Character({20, 60}, sf::Color::Red));
	kLlam.setPos({ 400,125 });
	
	//Ground Height, necesary for fiddling with gravity
	const int groundHeight = 220;


	//Main Game loop
	while (Window.isOpen()) {
		sf::Event Event;

		//Controls movement, left, right, and up
		//Currently, when you hold up you keep on going. It's pretty funny
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			kLlam.moveMe({ 0, -kLlam.gms() });
			kLlam.setJump(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			kLlam.moveMe({ kLlam.gms(),0 });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			kLlam.moveMe({-kLlam.gms(),0 });
		}

		//Event loop
		while (Window.pollEvent(Event)) {
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			
			//Closes the window if ESC is pressed
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();
				break;
			
			//If Up is released, the isJumping boolean is set to false
			case sf::Event::KeyReleased:
				if(Event.key.code == sf::Keyboard::Up)
					kLlam.setJump(false);
				break;

			}
		}

		//Basically gravity pulling the block down if it's not jumping and is above the ground height
		if ((kLlam.retY() < groundHeight) && (!kLlam.isJump())) {
			kLlam.moveMe({ 0 , kLlam.ggr() });
		}
		
		//move enemy across screen
		evilGuy.move(sf::Vector2f(evilGuy.getMoveSpeed(), 0));
		evilGuy.drawTo(Window);

		Window.clear();
		Window.draw(bimage);
		kLlam.drawMe(Window);
		Window.display();
		

	}


}