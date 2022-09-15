#include "mastship.h"

MastShip::MastShip(int m){
    mast = m;
}

void MastShip::addSwim(){
    swim = true;
}

void MastShip::destroySwim(){
    swim = false;
}

bool MastShip::checkSwim(){
    return swim;
}
