#include "MushroomField.h"

MushroomField::MushroomField(int size):size_{size}
{
     //Fill the vectors with all the possible positions
    for(auto i = 0.0f; i < 30.0f; i++){
        
        yPositions_.push_back(20.0f*(i+1.0f));
        
        if(i<25)  
        xPositions_.push_back(20.0f*(i+1.0f));
       
       }
    
      generateField();
}

void MushroomField::reset(){
    
    if(_mushrooms_ptr.size()> 0)
       _mushrooms_ptr.erase(_mushrooms_ptr.begin(), _mushrooms_ptr.end());  
 
    generateField();
}

void MushroomField::generateField(){
    
    
    srand(time(0));
    auto randy = 0;
    auto randx = 0;
    
     
   for(auto i = 0; i < size_; i++){
        
       //Acces at random indices
        randx = rand()%25;
        randy = rand()%30;
        
        _mushrooms_ptr.push_back(std::make_shared<Mushroom>(vector2D{MUSHROOM_SIZE},vector2D{xPositions_[randx],yPositions_[randy]},0.0f,ObjectID::MUSHROOM));
     
        }

    }

int MushroomField::size() const{
    
return size_;    
}
    
shared_ptr<Mushroom> MushroomField::mushroom(int i) const {
    
 return _mushrooms_ptr[i];    
    
}

MushroomField::~MushroomField()
{
}

