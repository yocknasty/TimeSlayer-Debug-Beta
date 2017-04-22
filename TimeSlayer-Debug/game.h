#include "header.h"
#include "menus.h"
#include "character.h"
#include "bullit.h"


class game : public screenInstance
{
public:
	game(void);
	void player(void);
	virtual int Run(sf::RenderWindow &App);

private:
	Player PlayerCharacter;
	sf::Texture bTexture;
	sf::Sprite bimage;
	int groundHeight;
	
};

game::game(void)
{
	//*****PUT ALL THE GLOBAL VALUES IN HERE*****

	//Generating the screen and window
	//sf::Vector2i screenDimensions(800, 250);
	
	//Initially loads the background
	if (!bTexture.loadFromFile("background2.png")) {
		std::cout << "Background failed to load!" << std::endl;
	}

	//Sets the background to the loaded image
	bimage.setTexture(bTexture);

	//Constant for ground height
	groundHeight = 340;
}

void game::player(void) {
	//Generates the player
	Player kLlam;
	kLlam.setCharacter(Character({ 20, 60 }, sf::Color::Red));
	kLlam.setPos({ 300,400 });
	PlayerCharacter = kLlam;

}

int game::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	player();
	bool Running = true;
	bool isFalling = false;
	PlayerCharacter.setPos({ 300,340 });
	//make all the bellets the player can shoot in a frame
	Bullet BulletArray[50];
	int i = 0;
	BulletArray[i].shot = false;


	int maxHeight = PlayerCharacter.getCharacter().maxJump();
	while (App.isOpen()) {
		
		if (PlayerCharacter.isJump()) {
			std::cout << "Curr Height: " << PlayerCharacter.retY() << " Max Height: " << maxHeight << std::endl;
			if (PlayerCharacter.retY() > maxHeight){
				PlayerCharacter.moveMe({ 0, -PlayerCharacter.gms()* 10 });
			}
			else{
				PlayerCharacter.setJump(false);

			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && PlayerCharacter.getCharacter().retY() > maxHeight) {
			if (!(PlayerCharacter.isJump())){
				PlayerCharacter.setJump(true);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			PlayerCharacter.moveMe({ PlayerCharacter.gms(),0 });

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			PlayerCharacter.moveMe({ -PlayerCharacter.gms(),0 });

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			sf::Vector2f HipPosition;
			HipPosition.x = PlayerCharacter.GetPos().x;
			HipPosition.y = PlayerCharacter.GetPos().y + 15;
			BulletArray[i].setPosition(HipPosition);
			BulletArray[i].shot = true;

		}
		BulletArray[i].move(1.0, 0);



		while (App.pollEvent(Event)) {
			//std::cout << "X: " << PlayerCharacter.retX() << " Y: " << PlayerCharacter.retY() << std::endl;
			//std::cout << "RelMax: " << relativeMax << " Y: " << PlayerCharacter.retY() << std::endl;
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
			/*case sf::Event::KeyReleased:
				if (Event.key.code == sf::Keyboard::Up)
					PlayerCharacter.setJump(false);
				break;*/

			}

		}

		if (PlayerCharacter.isJump()) {
			PlayerCharacter.moveMe({ 0, -PlayerCharacter.gms() });
			//std::cout << "Max Jump: " << relativeMax << " PlayerChar height: " << PlayerCharacter.retY() << std::endl;
		}
		
		//Basically gravity pulling the block down if it's not jumping and is above the ground height
		if ((PlayerCharacter.retY() < groundHeight) && (!PlayerCharacter.isJump())) {
			PlayerCharacter.moveMe({ 0 , PlayerCharacter.ggr() });

		}


		App.clear();
		App.draw(bimage);
		PlayerCharacter.drawMe(App);
		App.draw(BulletArray[i]);
		App.display();

	}
	//Never reaching this point normally, but just in case, exit the application
	return -1;
}