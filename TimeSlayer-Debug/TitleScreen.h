#include "header.h"
#include "menus.h"

//Title (Main Menu) class 
class title : public screenInstance
{
public:
	title(void);
	virtual int Run(sf::RenderWindow &App);

private:
	int alpha_max;
	int alpha_div;
	bool gameRunning;
};

//Title constructor; initial decleration
title::title(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	gameRunning = false;
}

//Title run function
int title::Run(sf::RenderWindow &App)
{
	
	//These are used for the backgrounds
	//sf::Texture Texture;
	sf::Sprite Sprite;
	
	//Sets the Running value to true
	bool Running = true;

	int alpha = 0;
	
	//Initial value 
	int menu = 0;

	//Sets the font value. Feel free to change it
	sf::Font Font;
	Font.loadFromFile("arial.ttf");

	//Menu option 1: Play (Starts a new game)
	sf::Text Menu1;
	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 160.f });

	//Menu option 2: Exit (Exits the game)
	sf::Text Menu2;
	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 220.f });

	//Menu option 3: Continue (Continues the game after it's been paused)
	sf::Text Menu3;
	Menu3.setFont(Font);
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition({ 280.f, 160.f });


	//Initial game event
	sf::Event Event;
	
	//Checks to see if the Title screen is running
	if (Running)
	{
		alpha = alpha_max;
	}

	//If the screen is running
	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						gameRunning = true;
						return (1);
					}
					else
					{
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}

		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max)
		{
			alpha++;
		}
		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
		{
			Menu1.setFillColor(sf::Color(255, 0, 0, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 0, 0, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(Sprite);
		if (alpha == alpha_max)
		{
			if (gameRunning)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		}
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}