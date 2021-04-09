#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
using namespace sf;

#ifndef Enemy_H
#define Enemy_H

class Enemy
{
public:
	/**
	* Default constructor, sets up the enemy starting position
	* @parm int - The starting x position
	* @parm int - The starting y position
	**/
	Enemy(int, int);

	/**
	* Default deconstructor
	**/
	~Enemy();

	/**
	* Allows for the enemies to shoot
	* @parm Nothing
	* @return Nothing
	**/
	void Shoot();

	/**
	* Updates the projectiles that the enemies shoot
	* @parm int - The projectile in the vector to update
	* @return Nothing
	**/
	void updateProjectiles(int);

	/*
	* Returns the vector that contains all the projectiles
	* @parm Nothing
	* @return vector<CircleShape> - The vector that contains the projectiles
	*/
	std::vector<CircleShape> getProjectiles();

	/**
	* Returns the shape of the enemies
	* @parm Nothing
	* @return CircleShape - The shape of the enemy
	**/
	CircleShape getShape();

	/**
	* Allows for the movement of the enemies
	* @parm Nothing
	* @return Nothing
	**/
	void move();

	/**
	* Returns the x position of the enemy
	* @parm Nothing
	* @return int - The original x position of the enemy
	**/
	int getPosition();

	/**
	* Allows for the left and right movement of the enemy
	* @parm bool - True if moving left, false if right
	* @return Nothing
	**/
	void backAndForth(bool);

private:

	/** 
	* The shape of the enemy 
	**/
	CircleShape shape;

	/** 
	* The shape of the enemies projectiles 
	**/
	CircleShape projectile;

	/** 
	* The vector containing the projectiles 
	**/
	std::vector<CircleShape> projectiles;

	/** 
	* the starting values of the enemies 
	**/
	int startX, startY;
};
#endif