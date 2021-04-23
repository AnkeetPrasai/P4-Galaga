#include "Player.h"
Display display;

Player::Player()
{
    shape.setRadius(20.f);
	shape.setPointCount(3);
	shape.setPosition(display.window.getSize().x / 2, 680);
	projectile.setRadius(5.f);
    projectile.setFillColor(sf::Color::Red);

    lives = 3;
	score = 0;
}

Player::~Player()
{

}

void Player::Movement(Event e)
{
switch (e.key.code)
      {

        case Keyboard::A:
          shape.move(-20, 0);
          if (!music.openFromFile("MoveSound.ogg"))
            return; // error
          music.play();
          break;

        case Keyboard::W:
          shape.move(0, -20);
    			if (!music.openFromFile("MoveSound.ogg"))
    				return; // error
    			music.play();
          break;

        case Keyboard::D:
          shape.move(20, 0);
    			if (!music.openFromFile("MoveSound.ogg"))
    				return; // error
  			  music.play();
          break;

        case Keyboard::S:
          shape.move(0, 20);
  			  if (!music.openFromFile("MoveSound.ogg"))
  				    return; // error
  			  music.play();
          break;

		//Up, Down, Left, Right mode
		case Keyboard::Left:
			shape.move(-20, 0);
			break;
		case Keyboard::Up:
			shape.move(0, -20);
			break;
		case Keyboard::Right:
			shape.move(20, 0);
			break;
		case Keyboard::Down:
			shape.move(0, 20);
			break;
}

		//Keeps track if the player ends up off the screen
		if (shape.getPosition().x < 0)
		{
			shape.setPosition(1280, shape.getPosition().y); //Resets if the player goes off the left side
		}
		else if (shape.getPosition().x > 1280)
		{
			shape.setPosition(0, shape.getPosition().y); //Resets if the player goes off the right side
		}
		else if (shape.getPosition().y < 0)
		{
			shape.setPosition(shape.getPosition().x, 720); //Resets if the player goes off the top
		}
		else if (shape.getPosition().y > 720)
		{
			shape.setPosition(shape.getPosition().x, 0); //Resets if the player goes off the bottom
		}
  // }
}

CircleShape Player::getShape()
{
    return shape;
}

void Player::Shoot()
{
	projectile.setPosition(shape.getPosition().x + 15, shape.getPosition().y + shape.getRadius());
	projectiles.push_back(CircleShape(projectile));
}

void Player::updateProjectiles(int i, std::vector<Enemy> &e, bool &test11)
{
	projectiles[i].move(0, -10.f);
	Rect<float> p(projectiles[i].getPosition().x, projectiles[i].getPosition().y, 10.f, 10.f);
	for (int j = 0; j < e.size(); j++)
	{
		Rect<float> en(e[j].getShape().getPosition().x, e[j].getShape().getPosition().y, 10.f, 10.f);
		if (p.intersects(en))
		{
			int numOfEnemies = e.size();
			e.erase(e.begin() + j);
      if (test11 == false)
  		{
        std::cout << "Test 11: Tests if enemies get removed if they get hit" << std::endl;
        	if (numOfEnemies > e.size())
  			  {
  				 std::cout << "TEST PASSED" << std::endl << std::endl;
           test11 = true;
  			  }
  			else
  			{
  				std::cout << "TEST FAILED" << std::endl << std::endl;
          test11 = true;
  			}
      }
      test11 = true;
			score = score + 100;
		}
	}
	if (projectiles[i].getPosition().y < 0)
	{
		projectiles.erase(projectiles.begin());
	}
}

std::vector<CircleShape> Player::getProjectiles()
{
	return projectiles;
}

bool Player::checkCollison(Enemy &e)
{
	bool collison = false;
	Rect<float> p(shape.getPosition().x, shape.getPosition().y, 40.f, 40.f);

	Rect<float> reborn_L(display.window.getSize().x/2 - 360, 680, 40.f, 40.f);
	Rect<float> reborn_M(display.window.getSize().x/ 2, 680, 40.f, 40.f);

	Rect<float> en(e.getShape().getPosition().x, e.getShape().getPosition().y, 10.f, 10.f);
	//small
	for (int i = 0; i < e.getProjectiles().size(); i++)
	{
		Rect<float> pro(e.getProjectiles()[i].getPosition().x, e.getProjectiles()[i].getPosition().y, 5.f, 5.f);
		if (p.intersects(pro))
		{
			lives--;
			if (p.intersects(reborn_L))
			{
				e.getShape().setPosition(e.getPosition(), 0);
				shape.setPosition(display.window.getSize().x / 2, 680);
			}
			else if (p.intersects(reborn_M))
			{
				e.getShape().setPosition(e.getPosition(), 0);
				shape.setPosition((display.window.getSize().x / 2) + 280, 680);
			}
			else
			{
				e.getShape().setPosition(e.getPosition(), 0);
				shape.setPosition(display.window.getSize().x / 2 - 280, 680);
			}
			collison = true;
			break;
		}
	}
	//big
	if (p.intersects(en))
	{
		lives--;
		if (p.intersects(reborn_L))
		{
			e.getShape().setPosition(e.getPosition(), 0);
			shape.setPosition(display.window.getSize().x/2, 680);
		}
		else if (p.intersects(reborn_M))
		{
			e.getShape().setPosition(e.getPosition(), 0);
			shape.setPosition((display.window.getSize().x / 2) + 280, 680);
		}
		else
		{
			e.getShape().setPosition(e.getPosition(), 0);
			shape.setPosition(display.window.getSize().x/2 - 280, 680);
		}
		collison = true;
	}
	return collison;
}

bool Player::gameOver()
{
	return (lives == 0);
}

int Player::getScore()
{
	return score;
}

int Player::getLives()
{
	return lives;
}
