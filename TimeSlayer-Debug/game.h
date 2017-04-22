#include "header.h"
#include "menus.h"
#include "character.h"
#define	MAX_ENEMIES 30

class game : public screenInstance
{
public:
	game(void);
	void player(void);
	void generateEnemy(void);
	virtual int Run(sf::RenderWindow &App);

private:
	Player PlayerCharacter;
	sf::Texture bTexture;
	sf::Sprite bimage;
	int groundHeight;
	int totalEnemies;
	Enemy *enemies[MAX_ENEMIES];
};

game::game(void)
{
	//*****PUT ALL THE GLOBAL VALUES IN HERE*****

	//Generating the screen and window
	//sf::Vector2i screenDimensions(800, 250);
	
	//Initially loads the background
	if (!bTexture.loadFromFile("Background.png")) {
		std::cout << "Background failed to load!" << std::endl;
	}

	//Sets the background to the loaded image
	bimage.setTexture(bTexture);

	//Constant for ground height
	groundHeight = 198;
	totalEnemies = 0;
}

void game::player(void) {
	//Generates the player
	Player kLlam;
	kLlam.setCharacter(Character({ 20, 60 }, sf::Color::Red));
	kLlam.setPos({ 300,300 });
	PlayerCharacter = kLlam;

}
//generate an enemeies randomly
void game::generateEnemy(void)
{
	int numberOfenemies = rand() % 3;
	totalEnemies += numberOfenemies;// adds the number generated to the total

	for (int i = 0; i < numberOfenemies ; i++)
	{
		enemies[i] = new Enemy;
		enemies[i]->setEnemy(Character({ 20,20 }, sf::Color::Green));
		enemies[i]->setPos({ 300.0 , 200.0 });
	}

}
int game::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	player();
	generateEnemy();
	bool Running = true;
	PlayerCharacter.setPos({ 300,300 });
	
	
	while (App.isOpen()) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			PlayerCharacter.moveMe({ 0, -PlayerCharacter.gms() });
			PlayerCharacter.setJump(true);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			PlayerCharacter.moveMe({ PlayerCharacter.gms(),0 });

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			PlayerCharacter.moveMe({ -PlayerCharacter.gms(),0 });

		}



		while (App.pollEvent(Event)) {
			//write player cords to the console
			std::cout << "X: " << PlayerCharacter.retX() << " Y: " << PlayerCharacter.retY() << std::endl;
			switch (Event.type)
			{
			case sf::Event::Closed:
				App.close();
				Running = false;
				return -1;

				//Closes the window if ESC is pressed
			case sf::Event::KeyPressed: 
				if (Event.key.code == sf::Keyboard::Escape){
					//App.close();
					Running = false;
					return 0;
				}

				//If Up is released, the isJumping boolean is set to false
			case sf::Event::KeyReleased:
				if (Event.key.code == sf::Keyboard::Up)
					PlayerCharacter.setJump(false);
				break;

			}

		}


		//Basically gravity pulling the block down if it's not jumping and is above the ground height
		if ((PlayerCharacter.retY() < groundHeight) && (!PlayerCharacter.isJump())) {
			PlayerCharacter.moveMe({ 0 , PlayerCharacter.ggr() });
		}

		App.clear();
		App.draw(bimage);
		for (int i = 0; i < totalEnemies; i++)
		{
			enemies[i]->moveEnemy({ enemies[i]->getMoveSpeed(), 0 });
			enemies[i]->drawEnemy(App);
		}
		

		
		
		PlayerCharacter.drawMe(App);
		
		App.display();

	}
	//Never reaching this point normally, but just in case, exit the application
	return -1;
}