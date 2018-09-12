#include "SplashScreen.h"


using  buttonTexture = sf::Texture;
using Button = sf::RectangleShape;

/*SplashScreen::SplashScreen(sf::RenderWindow& window):window_(window)
{

}*/

void SplashScreen::OpeningScreen()
{
    //Start button
    buttonTexture startTexture;
    startTexture.loadFromFile("start2.png");
    auto startButton = Button{sf::Vector2f(100.0f, 50.0f)};
    startButton.setPosition(220,330);
    startButton.setTexture(&startTexture);
    std::tie(a,b,c,d) = ButtonDimension(startButton);
    
    //Help button
    buttonTexture helpTexture;
    helpTexture.loadFromFile("redhelp.png");
    auto helpButton = Button{sf::Vector2f(100.0f, 50.0f)};
    helpButton.setPosition(220,420);
    helpButton.setTexture(&helpTexture);
     std::tie(e,f,g,h) = ButtonDimension(helpButton);
    
    //GameFont
    gameFont.loadFromFile("basson.ttf");
    gameText.setFont(gameFont);
    gameText.setCharacterSize(60);
    gameText.setPosition(130,140);
    gameText.setString("Centipede \nRevived!");
    gameText.setFillColor(sf::Color::Red);
    
    //Draw to window
     window_.draw(startButton);
     window_.draw(helpButton);
     window_.draw(gameText);
     
}

std::tuple <float, float, float, float> SplashScreen::ButtonDimension(Button button)
{
    auto a  =button.getPosition().x;
    auto b = button.getPosition().x + button.getSize().x ;
    auto c = button.getPosition().y;
    auto d = button.getPosition().y+ button.getSize().y;
    
    return std::make_tuple(a,b,c,d);
    
}

 void SplashScreen::HelpScreen()
 {
     //Back button
     buttonTexture backTexture;
    backTexture.loadFromFile("back.png");
    auto backButton = Button{sf::Vector2f(100.0f, 50.0f)};
    backButton.setPosition(220,450);
    backButton.setTexture(&backTexture);
    std::tie(q,r,y,t) = ButtonDimension(backButton);
    
    //Text for instructions
    gameText.setFillColor(sf::Color::White);
    gameText.setCharacterSize(40);
    gameText.setPosition(100,150);
    gameText.setString("Instructions" );
    window_.draw(gameText);
    
    gameText.setCharacterSize(15);
    gameText.setPosition(40, 200);
    gameText.setString("\n To Shoot: space \n \n Move Up: Up Arrow \n \n Move Down: Down Arrow \n \n Move Left: Left Arrow \n \n Move Right: Right Arrow");
    window_.draw(gameText);
    window_.draw(backButton);
     
     
     }

int SplashScreen::DetectButton(sf::Vector2i mousePos, float aspectRatioY, float aspectRatioX) 
{
    auto startButtonFlag = 1;
    auto helpButtonFlag = 2;
    auto backButtonFlag = 3;
    
            if( (aspectRatioX*mousePos.x >= a)   && (aspectRatioX*mousePos.x <= b))  {
                    if((aspectRatioY*mousePos.y >= c) && (aspectRatioY*mousePos.y <= d )){
                        
                        return startButtonFlag;       //start buttn
               }
             }

            if( (aspectRatioX*mousePos.x >= e)   && (aspectRatioX*mousePos.x <= f))  {
                 if((aspectRatioY*mousePos.y >= g) && (aspectRatioY*mousePos.y <= h )){
                            
                          return helpButtonFlag;    //help button
                            
                        }
               }
               
               
               if( (aspectRatioX*mousePos.x >= q)   && (aspectRatioX*mousePos.x <= r))  {
                    if((aspectRatioY*mousePos.y >= y) && (aspectRatioY*mousePos.y <= t)) {
                        
                        return backButtonFlag ;    //back button
                        }
               }
 return 0;
}



SplashScreen::~SplashScreen()
{
}

