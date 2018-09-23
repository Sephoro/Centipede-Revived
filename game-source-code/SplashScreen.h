#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Score.h"
#include "GameTypes.h"
#include "GameFiles.h"
#include <tuple>
#include <memory>
#include <vector>

enum class ScreenObjectID{START, HELP, BACK, EXIT, LOGO, BACKGROUND1, BACKGROUND2, LIFE};
//class FileNotFound{};


class SplashScreen
{
public:
    
    
    SplashScreen(sf::RenderWindow& window);
    //Draws the opening screen 
    void OpeningScreen();
    //Draws the helpscreen
    void HelpScreen();
    //Draws the game over screen
    void YouLoose();
    void YouWin();
    //Draws the Background of the gamescreen
    void GameScreen(int score, int lives);
    //Detects which button in the screen is being pressed
    ScreenObjectID DetectButton();
    ~SplashScreen();
   
private:

    //Gets dimensions  of the buttonsclTabCtrl
   std::tuple <float, float, float, float> ButtonDimension (sf::RectangleShape button);
   sf::RenderWindow& window_;
   //Makes buttons
   sf::RectangleShape DrawScreenObject(const vector2D& size,const vector2D& position, ScreenObjectID ID);
   //Stores button textures
   std::vector<sf::Texture> screenObjectTextures_;
   //These are the variables that represent the dimensions of each button
   float a, b, c,d;    //start button
   float e,f,g,h;      //help button
   float q,r,w,t;      //back button
   sf::Font gameFont;
   sf::Text gameText;
   
   GameFiles gamefile_;
  

};

#endif // SPLASHSCREEN_H
