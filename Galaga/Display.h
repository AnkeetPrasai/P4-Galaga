#include <iostream>
#include <vector>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

using namespace sf;
extern Music music;

#ifndef Display_H
#define Display_H

class Display
{
	public:
		
		/**
		* Default constructor, sets tup the window
		**/
		Display();

		/**
		* Default deconstructor
		**/
		~Display();

		/**
		* The window that gets used
		**/
		RenderWindow window;
};
#endif