#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

void StartScreen()
{
  // display.window.clear(sf::Color::Black);
  // sf::Image image1;
  // image1.create(1280 , 720);//1280 , 720
  // for (int i = 0; i < 1280; i++)
  // {
  //   for (int j = 0; j < 720; j++)
  //   {
  //   //  if (i % 30 == 0 || j % 30 == 0)
  //   //  {
  //   //    image1.setPixel(i,j, sf::Color::Red);
  //   //    }
  //   if (i > 256 && i < 1024 && j > 100 && j < 360)
  //   {
  //       image1.setPixel(i,j, sf::Color::Magenta);
  //   }
  //     else
  //     {
  //     image1.setPixel(i,j, sf::Color::Black);
  //     }
  //   }
  // }
  sf::Texture galagaLogo;
  sf::Sprite galagaScreen;
  galagaScreen.setPosition(display.window.getSize().x / 2 - 400, display.window.getSize().y / 2 - 200);

  sf::Texture pushSpaceKey;
  sf::Sprite spaceKeyScreen;
  spaceKeyScreen.setPosition(display.window.getSize().x / 2 - 200, display.window.getSize().y / 2 + 250);
  spaceKeyScreen.scale(2.f, 2.f);

  if (!galagaLogo.loadFromFile("GalagaLogo.png"))
  {
    cout << "Could not load Galaga image";
  }

  galagaScreen.setTexture(galagaLogo);

  if (!pushSpaceKey.loadFromFile("pushSpaceKey.jpg"))
  {
    cout << "Could not load push space key image";
  }
  spaceKeyScreen.setTexture(pushSpaceKey);


  // sf::Texture texture1;
  // texture1.loadFromImage(image1);
  // sf::Sprite sprite1(texture1);
  display.window.draw(galagaScreen);
  display.window.draw(spaceKeyScreen);
  // display.window.draw(sprite1);

  display.window.display();

  while (display.window.isOpen())
  {
      Event e;
      // Checks for any input from user and it send it to event handler
      while (display.window.pollEvent(e))
      {
          if (e.type == Event::KeyPressed)
          {
            if (e.key.code == Keyboard::Space)
            {
              display.window.clear();
              return;
            }
          }
      }
  }
}

void EndScreen()
{
  sf::Texture GameOver;
  sf::Sprite EndScreen;
  EndScreen.setPosition(display.window.getSize().x / 2 - 100, display.window.getSize().y / 2 - 100);

  if (!music.openFromFile("gameOverSound.ogg"))
  {
      return; // error
  }
  music.play();

  if (!GameOver.loadFromFile("GameOver.jpg"))
  {
    cout << "Could not load Game Over image" << endl;
  }

  EndScreen.setTexture(GameOver);

  display.window.draw(EndScreen);


  display.window.display();

  while (display.window.isOpen())
  {
      Event e;
      // Checks for any input from user and it send it to event handler
      while (display.window.pollEvent(e))
      {
          if (e.type == Event::KeyPressed)
          {
            if (e.key.code == Keyboard::Space)
            {
                  return;
            }
          }
      }
  }
}

void WinScreen()
{
  sf::Texture Win;
  sf::Sprite WinScreen;
  WinScreen.setPosition(display.window.getSize().x / 2 - 200, display.window.getSize().y / 2 - 200);

  if (!music.openFromFile("winSound.ogg"))
  {
      return; // error
  }
  music.play();

  if (!Win.loadFromFile("youWin.png"))
  {
    cout << "Could not load Winning Screen image" << endl;
  }

  WinScreen.setTexture(Win);

  display.window.draw(WinScreen);


  display.window.display();

  while (display.window.isOpen())
  {
      Event e;
      // Checks for any input from user and it send it to event handler
      while (display.window.pollEvent(e))
      {
          if (e.type == Event::KeyPressed)
          {
            if (e.key.code == Keyboard::Space)
            {
              return;
            }
          }
      }
  }
}

int Play()
{
    int test = 0;
    do
    {
        Texture scoreLogo;
        Sprite scoreSprite;
        if (!scoreLogo.loadFromFile("score.png"))
        {
            return -1;
        }
        scoreSprite.setTexture(scoreLogo);
        scoreSprite.setPosition(0, 700);

        Texture livesTexture;
        vector<Sprite> lives;
        if (!livesTexture.loadFromFile("galagaShip.png"))
        {
            return -1;
        }

        int check = 1;
        Text score;
        Font font;
        if (!font.loadFromFile("Dream MMA.ttf"))
        {
            return -1;
        }
        score.setStyle(Text::Bold);
        score.setFont(font);
        score.setPosition(125, 690);

        sf::Music music;
        display.window.clear();
        int check1 = 1;
        if (!music.openFromFile("GalagaTheme.ogg"))
        {
             return -1; // error
        }
        music.play();
        StartScreen();
        music.stop();
        Player p;
        vector<Enemy> enemies;
        for (int i = 0; i < 20; i++)
        {
            enemies.push_back(Enemy(i * 30 + 300, 0));
        }

        for (int i = 0; i < p.getLives(); i++)
        {
            lives.push_back(Sprite(livesTexture));
            lives[i].setPosition(1100 + (i * 50), 680);
        }

        int time = 0;
        bool left = false;
        string scoreDisplay;
        while (display.window.isOpen() && check1 == 1)
        {
            Event e;
            // Checks for any input from user and it send it to event handler
            while (display.window.pollEvent(e) || check && check1 == 1)
            {
                scoreDisplay = to_string(p.getScore());
                score.setString(scoreDisplay);
                 if (e.type == Event::KeyPressed)
                 {
                    if (e.key.code == Keyboard::Space)
                       {
                                        // if (e.key.code == Keyboard::Space && e.key.code == Keyboard::A)
                                        // {
                                        // p.Movement(e);
                         p.Shoot();
                         if (!music.openFromFile("Laser.ogg"))
                            {
                                return -1; // error
                            }
                         music.play();
                       }
                       else if (e.key.code == Keyboard::Escape)
                       {
                             display.window.close();
                             check = 0;
                             check1 = 0;
                             test = 1;
                       }
                       else
                       {
                            p.Movement(e);
                       }
                 }
                 if (e.type == Event::Closed)
                 {
                     display.window.close();
                     check = 0;
                 }
                 if (p.gameOver())
                 {
                     check1 = 0;
                     EndScreen();
                     break;
                 }
                 if (enemies.size() == 0)
                 {
                     check1 = 0;
                     check = 0;
                     WinScreen();
                 }

                 int selection = 0;
                 int random = 0;
                 if (enemies.size() == 0) // Breaks out of the loop if the player wins
                 {
                     break;
                 }
                 int check = 0;
                 int previous = 0;
                 selection = rand() % enemies.size(); //Randomly selects an enemy ship
                 random = rand() % enemies.size();
                 for (int i = 0; i < enemies.size(); i++) //Checks if any ship has started moving
                 {
                     if (enemies[i].getShape().getPosition().y == 0)
                     {
                         check++;
                     }
                     else
                     {
                         previous = i;
                     }
                 }
                 if (check == enemies.size()) //If no enemy has moved, the randomly selected one moves
                 {
                     enemies[selection].move();
                     enemies[random].Shoot();
                 }
                 else //Otherwise the one that has moved continues moving
                 {
                     enemies[previous].move();
                 }
                 if (time == 0)
                 {
                     left = true;
                 }
                 else
                 {
                     time--;
                 }
                 for (int i = 0; i < enemies.size(); i++)
                 {
                     enemies[i].backAndForth(left);
                 }
                 if (enemies[0].getShape().getPosition().x < 100 && time == 0)
                 {
                     time = 200;
                     left = false;
                     enemies[random].Shoot();
                 }
                 //Clears the window
                 display.window.clear();

                 for (int i = 0; i < p.getProjectiles().size(); i++) //Updates the projectiles with their new positions
                 {
                     p.updateProjectiles(i, enemies);
                 }

                 for (int i = 0; i < enemies.size(); i++)
                 {
                     for (int j = 0; j < enemies[i].getProjectiles().size(); j++)
                     {
                         enemies[i].updateProjectiles(j);
                     }
                 }

                 display.window.draw(p.getShape()); //Draws the player on the screen

                 for (int i = 0; i < p.getProjectiles().size(); i++) //Draws the player's projectiles on the screen
                 {
                     display.window.draw(p.getProjectiles()[i]);
                 }

                 for (int i = 0; i < enemies.size(); i++)
                 {
                     for (int j = 0; j < enemies[i].getProjectiles().size(); j++)
                     {
                         display.window.draw(enemies[i].getProjectiles()[j]);
                     }
                 }

                 display.window.draw(score);
                 display.window.draw(score);
                 display.window.draw(scoreSprite);

                 for (int i = 0; i < p.getLives(); i++)
                  {
                     display.window.draw(lives[i]);
                 }


                 for (int i = 0; i < enemies.size(); i++)
                 {
                     p.checkCollison(enemies[i]);
                 }

                 for (int i = 0; i < enemies.size(); i++) //Draws the enemies on the screen
                 {
                     display.window.draw(enemies[i].getShape());
                 }

                 //Displays the new frame
                 display.window.display();
            }
        }
    }while (test == 0);
   return 0;
}

int main()
{
  Play();
  std::cout << "Hello World!\n";
  return 0;
}
