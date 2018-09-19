#include "Player.h"
#include "LazerShot.h"
#include "Display.h"
#include "Constants.h"
#include "UserInputs.h"
#include <memory>


int main(){
    
    
    auto loaded = true;
    
    auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE ,PLAYER_Y_SIZE},PLAYER_START_POSTION, 1.0f, ObjectID::PLAYER);
    auto D1 = std::make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},vector2D{240.0f,450.0f}, 1.0f, ObjectID::BULLET);
    auto userInput = std::make_shared<UserInputs>();
    
 
    
   
    
    while(D1->isOpen()){
        
         if(userInput->pressedKey()==Key::UP){
             
             P1->Move(Direction::UP);
             }
        if(userInput->pressedKey()==Key::DOWN){
             
              P1->Move(Direction::DOWN);
            }
          if(userInput->pressedKey()==Key::LEFT){
             
             P1->Move(Direction::LEFT);
             }
         if(userInput->pressedKey()==Key::RIGHT){
             
             P1->Move(Direction::RIGHT);
         }
    
        
         if(loaded)   
         {L1->Load(P1->getPosition());
         loaded = false;
         }
         

         L1->Fire();
       
         D1->drawObject(L1);
         D1->drawObject(P1);
         D1->display();
        
        }
     
    
return 0;

}