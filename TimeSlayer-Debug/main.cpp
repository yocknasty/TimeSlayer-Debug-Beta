/* 
	YuNg EnGiNeEr
	If you don't know what this is by now
	this is going to be a long project.
*/

#include "character.h"
#include "TitleScreen.h"
#include "game.h"

using std::endl;
using std::string;

int main() {

	std::vector<screenInstance*> Screens;
	int screen = 0;

	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Time Slayer");

	App.setMouseCursorVisible(false);

	title s0;
	Screens.push_back(&s0);
	game s1;
	Screens.push_back(&s1);

	while (screen >= 0) {
		screen = Screens[screen]->Run(App);
	}
}