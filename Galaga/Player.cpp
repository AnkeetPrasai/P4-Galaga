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
//   bool up = false;
//   bool down = false;
//   bool right = false;
//   bool left = false;
//   // int a = 0;
//         // switch (e.key.code)
//       // while (display.window.pollEvent(e))
//       // {
//         std::cout << "test2";
//
//
//     while (display.window.isOpen()) {
//       while (display.window.pollEvent(e)) {
//         switch (e.type)
//         {
//   		//AWDS
//           case Event::KeyPressed:
//             if (e.key.code == Keyboard::A)
//             {
//               left = true;
//             }
//             else if (e.key.code == Keyboard::W)
//             {
//               up = true;
//             }
//             else if (e.key.code == Keyboard::S)
//             {
//               down = true;
//             }
//             else if (e.key.code == Keyboard::D)
//             {
//               right = true;
//
//             }
//             break;
//           case Event::KeyReleased:
//             if (e.key.code == Keyboard::A)
//             {
//               left = false;
//             }
//            else if (e.key.code == Keyboard::W)
//             {
//               up = false;
//             }
//             else if (e.key.code == Keyboard::S)
//             {
//               down = false;
//             }
//             else if (e.key.code == Keyboard::D)
//             {
//               right = false;
//             }
//             break;
//           case Event::Closed:
//             display.window.close();
//             break;
//           default:
//             break;
//         }
//       }
//
//
//       if (up && down)
//       {
//         std::cout << "Moving up and down" << std::endl;
//         shape.move(0, -20);
//         shape.move(0, 20);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (up && left)
//       {
//         std::cout << "Moving up and left" << std::endl;
//         shape.move(0, -20);
//         shape.move(-20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (up && right)
//       {
//        std::cout << "Moving up and right" << std::endl;
//         shape.move(0, -20);
//         shape.move(20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (down && left)
//       {
//         std::cout << "Moving down and left" << std::endl;
//         shape.move(0, 20);
//         shape.move(-20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (down && right)
//       {
//         std::cout << "Moving down and right" << std::endl;
//         shape.move(0, -20);
//         shape.move(20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (left && right)
//       {
//         std::cout << "Moving left and right" << std::endl;
//         shape.move(-20, 0);
//         shape.move(20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//           return; // error
//         music.play();
//       }
//       else if (up)
//       {
//         std::cout << "Moving up" << std::endl;
//         shape.move(0, -20);
//       	if (!music.openFromFile("MoveSound.ogg"))
//       		return; // error
//       	music.play();
//       }
//       else if (right)
//       {
//         std::cout << "Moving right" << std::endl;
//         shape.move(20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//            return; // error
//         music.play();
//       }
//       else if (down)
//       {
//           std::cout << "Moving down" << std::endl;
//           shape.move(0, 20);
//     		  if (!music.openFromFile("MoveSound.ogg"))
//     			    return; // error
//     		  music.play();
//       }
//       else if (left)
//       {
//         std::cout << "Moving left" << std::endl;
//         shape.move(-20, 0);
//         if (!music.openFromFile("MoveSound.ogg"))
//             return; // error
//         music.play();
//       }
//       else
//       {
//
//       }

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

void Player::updateProjectiles(int i, std::vector<Enemy> &e)
{
	projectiles[i].move(0, -10.f);
	Rect<float> p(projectiles[i].getPosition().x, projectiles[i].getPosition().y, 10.f, 10.f);
	for (int j = 0; j < e.size(); j++)
	{
		Rect<float> en(e[j].getShape().getPosition().x, e[j].getShape().getPosition().y, 10.f, 10.f);
		if (p.intersects(en))
		{
			e.erase(e.begin() + j);
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
	Rect<float> en(e.getShape().getPosition().x, e.getShape().getPosition().y, 10.f, 10.f);
	for (int i = 0; i < e.getProjectiles().size(); i++)
	{
		Rect<float> pro(e.getProjectiles()[i].getPosition().x, e.getProjectiles()[i].getPosition().y, 5.f, 5.f);
		if (p.intersects(pro))
		{
			lives--;
			e.getShape().setPosition(e.getPosition(), 0);
			shape.setPosition(display.window.getSize().x / 2, 680);
			collison = true;
		}
	}
	if (p.intersects(en))
	{
		lives--;
		shape.setPosition(display.window.getSize().x / 2, 680);
		e.getShape().setPosition(e.getPosition(), 0);
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