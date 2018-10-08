#ifndef SCORE_H
#define SCORE_H
#include "GameFiles.h"
#include <memory>

class Score
{
public:
    Score();
    //incremenet score by 10 
    void centibodyDestroyed();
    //incremenet score by 100 
    void centiheadDestroyed();
    //incremenet score by 1
    void mushroomDestroyed();
    //increment score by 300
    void spiderDestroyed();
    //increment score by 1000
    void scorpionDestroyed();
    //get score
    int score() const;
    //reset score 
    void reset();
    //update high score
    void updateHighscore();
    ~Score();
private:
        int score_;

};

#endif // SCORE_H
