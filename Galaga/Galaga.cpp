
#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

void StartScreen()
{
  sf::Texture galagaLogo;
  sf::Sprite galagaScreen;
  sf::Texture pushSpaceKey;
  sf::Sprite spaceKeyScreen;
  galagaScreen.setPosition(display.window.getSize().x / 2 - 400, display.window.getSize().y / 2 - 200);
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
  display.window.draw(galagaScreen);
  display.window.draw(spaceKeyScreen);
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

void LoseScreen()
{
  if (!music.openFromFile("gameOverSound.ogg"))
  {
      return; // error
  }
  music.play();

  sf::Texture GameOver;
  sf::Sprite LoseScreen;
  LoseScreen.setPosition(display.window.getSize().x / 2 - 100, display.window.getSize().y / 2 - 100);

  if (!GameOver.loadFromFile("GameOver.jpg"))
  {
    cout << "Could not load Game Over image" << endl;
  }

  LoseScreen.setTexture(GameOver);
  display.window.draw(LoseScreen);
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
  if (!music.openFromFile("winSound.ogg"))
  {
      return; // error
  }
  music.play();

  sf::Texture Win;
  sf::Sprite WinScreen;
  WinScreen.setPosition(display.window.getSize().x / 2 - 200, display.window.getSize().y / 2 - 200);

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

void scoreScreen()
{





























}

int levelTwo(Player& p)
{
    sf::Music music;
    bool activeGame = true;
    do
    {
        int check = 1;
        int check1 = 1;

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

        Text score;
        Font font;

        if (!font.loadFromFile("Dream MMA.ttf"))
        {
            return -1;
        }

        score.setStyle(Text::Bold);
        score.setFont(font);
        score.setPosition(125, 690);
        display.window.clear();

        if (!music.openFromFile("GalagaTheme.ogg"))
        {
            return -1; // error
        }

        music.play();
        music.stop();

        vector<Enemy> enemies;

        for (int i = 0; i < 30; i++)
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
                        activeGame = false;
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
                    check = 0;
                    LoseScreen();
                    activeGame = false;
                }
                if (enemies.size() == 0)
                {
                    check1 = 0;
                    check = 0;
                    WinScreen();
                    activeGame = false;
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
    } while (activeGame == true);
    return 0;
}

int levelOne()
{
  sf::Music music;
  bool activeGame = true;
  do
  {
    int check = 1;
    int check1 = 1;

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

    Text score;
    Font font;

    if (!font.loadFromFile("Dream MMA.ttf"))
    {
        return -1;
    }

    score.setStyle(Text::Bold);
    score.setFont(font);
    score.setPosition(125, 690);
    display.window.clear();

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
                         activeGame = false;
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
                 LoseScreen();
                 break;
             }
             if (enemies.size() == 0)
             {
                 check1 = 0;
                 check = 0;
                 levelTwo(p);
                 if (display.window.isOpen() == false)
                 {
                     activeGame = false;
                 }
                 if (p.getLives() > 0)
                 {
                     WinScreen();
                 }
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
  } while (activeGame == true);
 return 0;
}

void TestSuite()
{
  int test1 = 0;
  cout << "Test 1: " << "Program detects if user has won game.\n";
  if (test1 == true)
  {
    cout << "PASSED TEST\n";
  }
  else
  {
    cout << "FAILED TEST\n";
  }
}

int main()
{
  levelOne();
  TestSuite();
  return 0;
}
