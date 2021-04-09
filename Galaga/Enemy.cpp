#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	shape.setRadius(10.f);
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	startX = x;
	startY = y;
	projectile.setRadius(5.f);
	projectile.setFillColor(sf::Color::Red);
}

Enemy::~Enemy()
{

}

void Enemy::Shoot()
{
	projectile.setPosition(shape.getPosition().x + 15, shape.getPosition().y + shape.getRadius());
	projectiles.push_back(CircleShape(projectile));
}

void Enemy::updateProjectiles(int i)
{
	projectiles[i].move(0, 10.f);
	if (projectiles[i].getPosition().y > 720)
	{
		projectiles.erase(projectiles.begin());
	}
}

CircleShape Enemy::getShape()
{
	return shape;
}

std::vector<CircleShape> Enemy::getProjectiles()
{
	return projectiles;
}

void Enemy::move()
{
	shape.move(0, 5.f);
	if (shape.getPosition().y > 720)
	{
		shape.setPosition(startX, 0);
	}
}

int Enemy::getPosition()
{
	return startX;
}

void Enemy::backAndForth(bool left)
{
	if (left == true)
	{
		shape.move(-2.f, 0);
	}
	else
	{
		shape.move(2.f, 0);
	}
}
