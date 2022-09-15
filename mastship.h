#ifndef MASTSHIP_H_
#define MASTSHIP_H_

#include <string>

class MastShip{
private:
    bool swim = 0;
    int mast;
public:
    MastShip();
    MastShip(int m);
    
    void addSwim();
    void destroySwim();
    bool checkSwim();
};

#endif