#include <iostream>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

void TestSuite()
{
  cout << "Test 1: " << "Program detects if theme song is in file.\n";
  if (music.openFromFile("GalagaTheme.ogg"))
  {
    cout << "PASSED TEST\n\n";
  }
  else
  {
    cout << "FAILED TEST\n\n";
  }

  cout << "Test 2: " << "Program detects if shoot sound is in file.\n";
  if (music.openFromFile("Laser.ogg"))
  {
    cout << "PASSED TEST\n\n";
  }
  else
  {
    cout << "FAILED TEST\n\n";
  }

  cout << "Test 3: " << "Program detects if Galaga Theme Logo is in file.\n";
  sf::Texture galagaLogo;
  if (galagaLogo.loadFromFile("GalagaLogo.png"))
  {
    cout << "PASSED TEST\n\n";
  }
  else
  {
    cout << "FAILED TEST\n\n";
  }

  cout << "Test 4: " << "Program detects if Push Space Key Image is in file.\n";
  sf::Texture pushSpaceKey;
  if (pushSpaceKey.loadFromFile("pushSpaceKey.jpg"))
  {
    cout << "PASSED TEST\n\n";
  }
  else
  {
    cout << "FAILED TEST\n\n";
  }

  cout << "Test 5: " << "Program can detect player not moving.\n";
  Player p;
  Event e;
  int endf = 0;
  while (display.window.pollEvent(e) && endf == 0)
  {
    if (!(e.type == Event::KeyPressed))
    {
      if (!(e.key.code == Keyboard::A))
      {
        cout << "PASSED TEST\n\n";
      }
      else
      {
        cout << "FAILED TEST\n\n";
      }
    }
    endf = 1;
  }


  cout << "Test 6: " << "Program can detect player 'AWSD' keyboard presses. \n";
  while (display.window.isOpen() && ((endf == 0) || (endf == 1)))
  {
    while (display.window.pollEvent(e) && ((endf == 0) || (endf == 1)))
    {
      if ((e.type == Event::KeyPressed))
      {
        if ((e.key.code == Keyboard::A || e.key.code == Keyboard::W || e.key.code == Keyboard::S || e.key.code == Keyboard::D))
        {
          cout << "PASSED TEST\n\n";
          endf = 2;
        }
        else
        {
          cout << "WRONG INPUT, TYPE one of the following letters: 'W' 'A 'S' 'D'\n\n";
        }
      }
    }

  }
}

void LevelDisplay(int i)
{
    string i2 = to_string(i);
    Text level;
    Font font1;
    if (!font1.loadFromFile("OriginTech personal use.ttf"))
    {
        return;
    }

    level.setStyle(Text::Bold);
    level.setFont(font1);
    level.setPosition(550, 360);
    level.setCharacterSize(50);
    level.setString("LEVEL " + i2);
    display.window.draw(level);
    display.window.display();
    while (display.window.isOpen())
    {
        Event e;
        // Checks for any input from user and it send it to event handler
        while (display.window.pollEvent(e))
        {
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Enter || e.key.code == Keyboard::Space)
                {
                    display.window.clear();
                    return;
                }
            }
        }
    }
}

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
        else if (e.key.code == Keyboard::Tab) {
          TestSuite();
        }
      }
    }
  }
  cout << "TEST FAILED" << endl;
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

    display.window.clear();
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

  //
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
  //
  //while (display.window.isOpen())
  //{
  //    Event e;
  //    //string check[3];
  //    string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
  //    // Checks for any input from user and it send it to event handler
  //    while (display.window.pollEvent(e))
  //    {
  //        for (int i = 0; i < 3; i++) {
  //            if (e.type == Event::KeyPressed)
  //            {
  //                array[i] = alphabet[e.key.code];
  //            }
  //        }

  //    }
  //}
  //
  //Font font1;
  //if (!font1.loadFromFile("OriginTech personal use.ttf"))
  //{
  //    return;
  //}
  //Text title("Congratulations on a High score", font1, 60);
  //title.setPosition(400, 100);
  //Text header("ENTER A 3 Letter Alias: ", font1, 25);
  //header.setPosition(400, 300);

  //display.window.draw(title);
  //display.window.draw(header);

  //display.window.display();
  //
  //while (display.window.isOpen())
  //{
  //  Event e;
  //    // Checks for any input from user and it send it to event handler
  //  while (display.window.pollEvent(e))
  //  {
  //    if (e.type == Event::KeyPressed)
  //    {
  //      if (e.key.code == Keyboard::Space)
  //      {
  //        return;
  //      }
  //     }
  //  }
  //}
}

void scoreScreen(Player & p)
{
    display.window.clear();
    Font font1;
    if (!font1.loadFromFile("OriginTech personal use.ttf"))
    {
        return;
    }
    
    string score = to_string(p.getScore());
    string scoreArray[5];
    string initialArray[5];
    string line;
    char winner[3];
    string initial;
    int i = 0;

    ifstream myfile("Leaderboard.txt");
    if (myfile.is_open())
    {
        cout << "Test 12: Makes sure leaderboard.txt file still has data" << endl;
        while (i < 5)
        {
            getline(myfile, line);
            scoreArray[i] = line;
            i++;
        }
        i = 0;
        while (i < 5)
        {
            getline(myfile, line);
            initialArray[i] = line;
            i++;
        }
        myfile.close();
    }

    if (scoreArray[0] != "")
    {
        cout << "TEST PASSED" << endl << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl << endl;
    }
    //
    //
    //
    //
    //
    //
    if (stoi(score) > stoi(scoreArray[4])) {


        Text title("Congratulations on a High Score!", font1, 60);
        title.setPosition(50, 100);
        Text header("Enter a 3 Letter alias for the Score Board ", font1, 20);
        header.setPosition(250, 300);

        display.window.draw(title);
        display.window.draw(header);

        display.window.display();

        while (display.window.isOpen())
        {
            Event e;
            // Checks for any input from user and it send it to event handler
            while (display.window.pollEvent(e))
            {
                //string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
                // Checks for any input from user and it send it to event handler
                for (int i = 0; i < 3; i++) {
                    display.window.setKeyRepeatEnabled(false);
                    if (e.type == Event::TextEntered)
                    {

                        if (e.text.unicode < 128) {
                            std::cout << "ASCII character typed: " << static_cast<char>(e.text.unicode) << std::endl;
                            winner[i] = static_cast<char>(e.text.unicode);
                        }
                        /*cout << e.key.code << "/n";
                        winner[i] = alphabet[e.key.code % 27];
                        cout << winner[i] << " " << "/n";*/
                    }
                }

                display.window.clear();
                break;

            }
        }
        initial.append(winner);
        cout << initial << " " << " fuck you ";

    }
    //
    //
    //
    //
    //
    //
    //

    if (stoi(score) > stoi(scoreArray[4]))
    {
         scoreArray[4] = score;
        initialArray[4] = initial;
        cout << "Test 14: Checks if the player score gets added if its greater than a previous score on leaderboard" << endl;
        if (scoreArray[4] == score)
        {
            cout << "TEST PASSED" << endl << endl;
        }
        else
        {
            cout << "TEST FAILED" << endl << endl;
        }
    }


    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (stoi(scoreArray[i]) < stoi(scoreArray[j]))
            {
                string tempScore;
                string tempInitial;
                tempScore = scoreArray[i];
                tempInitial = initialArray[i];
                scoreArray[i] = scoreArray[j];
                initialArray[i] = initialArray[j];
                scoreArray[j] = tempScore;
                initialArray[j] = tempInitial;
            }
        }
    }
    display.window.clear();

    Text title("LEADERBOARD", font1, 60);
    title.setPosition(400, 100);
    Text header("SCORE              NAME", font1, 25);
    header.setPosition(400, 300);

    Text first("1ST: " + scoreArray[0] + "                " + initialArray[0], font1, 25);
    Text second("2ND: " + scoreArray[1] + "               " + initialArray[1], font1, 25);
    Text third("3RD: " + scoreArray[2] + "               " + initialArray[2], font1, 25);
    Text fourth("4TH: " + scoreArray[3] + "               " + initialArray[3], font1, 25);
    Text fifth("5TH: " + scoreArray[4] + "               " + initialArray[4], font1, 25);

    first.setPosition(400, 360);
    second.setPosition(400, 400);
    third.setPosition(400, 440);
    fourth.setPosition(400, 480);
    fifth.setPosition(400, 520);

    display.window.draw(title);
    display.window.draw(header);
    display.window.draw(first);
    display.window.draw(second);
    display.window.draw(third);
    display.window.draw(fourth);
    display.window.draw(fifth);
    display.window.display();

    ofstream write("Leaderboard.txt");
    if (write.is_open())
    {
        for (int i = 0; i < 5; i++)
        {
            write << scoreArray[i] << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            write << initialArray[i] << endl;
        }
        write.close();
    }

    while (display.window.isOpen())
    {
        Event e;
        // Checks for any input from user and it send it to event handler
        while (display.window.pollEvent(e))
        {
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Enter || e.key.code == Keyboard::Space)
                {
                    display.window.clear();
                    return;
                }
            }
        }
    }
}

int levelTwo(Player& p, string winner[]) {
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
        LevelDisplay(2);

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
                        cout << "Test 9: Tests if pressing ESC closes the program" << endl;
                        if (display.window.isOpen() == false)
                        {
                            cout << "TEST PASSED" << endl << endl;
                        }
                        else
                        {
                            cout << "TEST FAILED" << endl << endl;
                        }
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
                    cout << "Test 15: Checks if the game ends if the player runs out of lives" << endl;
                    check1 = 0;
                    if (check1 == 0)
                    {
                        cout << "TEST PASSED" << endl << endl;
                    }
                    else
                    {
                        cout << "TEST FAILED" << endl << endl;
                    }
                    LoseScreen();
                    break;
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
                                         
                                         
                                         
                                         
                                         // win condition for GAME 2
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
            activeGame = false;
        }
    } while (activeGame == true);
    return 0;
}

int levelOne()
{
  sf::Music music;
  bool activeGame = true;
  string winner[3];
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
    cout << "Test 13: Makes sure the user can exit the start screen" << endl;
    StartScreen();
    cout << "TEST PASSED" << endl << endl;
    display.window.clear();
    LevelDisplay(1);
    music.stop();

    Player p;
    vector<Enemy> enemies;

    scoreScreen(p);

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
                     int size = p.getProjectiles().size();
                     p.Shoot();
                     cout << "Test 8: Tests the shooting mechanic of the game if the user presses space" << endl;
                     if (size < p.getProjectiles().size())
                     {
                         cout << "TEST PASSED" << endl << endl;
                     }
                     else
                     {
                         cout << "TEST FAILED" << endl << endl;
                     }
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
                         cout << "Test 9: Tests if pressing ESC closes the program" << endl;
                         if (display.window.isOpen() == false)
                         {
                             cout << "TEST PASSED" << endl << endl;
                         }
                         else
                         {
                             cout << "TEST FAILED" << endl << endl;
                         }
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
                 cout << "Test 15: Checks if the game ends if the player runs out of lives" << endl;
                 check1 = 0;
                 if (check1 == 0)
                 {
                     cout << "TEST PASSED" << endl << endl;
                 }
                 else
                 {
                     cout << "TEST FAILED" << endl << endl;
                 }
                 LoseScreen();
                 break;
             }
             if (enemies.size() == 0)
             {
                 cout << "Test 16: Checks if the game ends if the player destroys all enemies" << endl;
                 check1 = 0;
                 check = 0;
                 levelTwo(p, winner);
                 if (display.window.isOpen() == false)
                 {
                     activeGame = false;
                 }
                 if (p.getLives() > 0)
                 {
                     WinScreen();
                 }
                 activeGame = false;
                 if (activeGame == false)
                 {
                     cout << "TEST PASSED" << endl << endl;
                 }
                 else
                 {
                     cout << "TEST FAILED" << endl << endl;
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
                 int numOfLives = p.getLives();
                 if (p.checkCollison(enemies[i]) == true)
                 {
                     cout << "Test 7: Tests if the player loses a life if they get hit" << endl;
                     if (p.getLives() < numOfLives)
                     {
                         cout << "TEST PASSED" << endl << endl;
                     }
                     else
                     {
                         cout << "TEST FAILED" << endl << endl;
                     }
                 }
             }

             for (int i = 0; i < enemies.size(); i++) //Draws the enemies on the screen
             {
                 display.window.draw(enemies[i].getShape());
             }

             //Displays the new frame
             display.window.display();
        }
    }
    scoreScreen(p);
  } while (activeGame == true);
 return 0;
}

int main()
{
  TestSuite();
  levelOne();
  return 0;
}
