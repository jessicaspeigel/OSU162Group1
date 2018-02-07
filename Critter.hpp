/****************************************************************************
 ** Author: 
 ** Date: 
 ** Description: Critter Header File, abstract base class for Ant and
        Doodlebug classes
 ****************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter 
{
private: 
    int timeSinceBreed; //track time since last breeding
    int row; //track critter row
    int col; //track critter col    
public: 
    Critter(int, int);
    //virtual void move() = 0; 
    void incrementTime();  
    void resetTime();   //call after breeding to reset clock to 0
    int getTime(); 
    Critter* breed(int, int); //input row and col, returns pointer to new Critter
    virtual ~Critter(); 
}; 

#endif
