#include "Display.h"
sf::Music music;

Display::Display():window(VideoMode(1280, 720), "GALAGA", Style::None)
{
	window.setFramerateLimit(60);
}

Display::~Display()
{

}
