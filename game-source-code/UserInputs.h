#ifndef USERINPUTS_H
#define USERINPUTS_H
#include <SFML/Graphics.hpp>

enum class Key{LEFT,RIGHT,UP,DOWN,SPACE,OTHERS};

class UserInputs
{
public:
    UserInputs(){};
    //Return Pressed Key
    Key pressedKey();
    ~UserInputs(){};

};

#endif // USERINPUTS_H
