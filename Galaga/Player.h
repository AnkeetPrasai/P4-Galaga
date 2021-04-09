#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Display.h"
#include "Enemy.h"
#include <vector>


using namespace sf;
extern Display display;

#ifndef Player_H
#define Player_H

class Player
{
	public:

		/**
		* Default constructor, sets the player up with lives and their shape
		**/
		Player();

		/**
		* Standard deconstructor
		**/
		~Player();

		/**
		* Allows for the movement with the player
		* @parm Event - The event to keep track of key presses
		* @return Nothing
		**/
		void Movement(Event);

		/*
		* Allows the player to shoot
		* @parm Nothing
		* @return Nothing
		*/
		void Shoot();

		/**
		* Checks if the player has lost
		* @parm Nothing
		* @return bool - If the player has lost, return true
		**/
		bool gameOver();

		/**
		* Returns the shape of player
		* @parm Nothing
		* @return CircleShape - The shape that the player uses
		**/
		CircleShape getShape();

		/**
		* Updates all of the projectiles the player shot and see if there are any collisions
		* @parm int - The projectile to update
		* @parm vector<Enemy> - The vector holding all of the enemies on the board
		* @return Nothing
		**/
		void updateProjectiles(int, std::vector<Enemy>&);

		/**
		* Returns all the projectiles that the player has shot
		* @parm Nothing
		* @return vector<CircleShape> - Vector containing all of the shots the player has shot
		**/
		std::vector<CircleShape> getProjectiles();

		/**
		* Checks if the player has been hit
		* @parm Enemy - The enemy that ran into the player
		* @parm bool - Returns true if the player is hit
		**/
		bool checkCollison(Enemy&);

		/**
		* Returns the score of the player
		* @parm Nothing
		* @parm int - Returns the value of the player's score
		**/
		int getScore();

		/**
		* Returns the number of lives the player has
		* @parm Nothing
		* @parm int - Returns the number of lives the player has
		**/
		int getLives();
		
	private:
		/**
		* The total number of lives the player has 
		**/
		int lives;

		/**
		* The triangle shape of the user 
		**/
		CircleShape shape;

		/** 
		* The circle shape of the projectiles they shoot 
		**/
		CircleShape projectile;

		/** 
		* The vector containing all of the projectiles the player has shot 
		**/
		std::vector<CircleShape> projectiles;

		/** 
		* The score that the player has 
		**/
		int score;
};
#endif