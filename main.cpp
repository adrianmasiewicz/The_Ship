#include <iostream>
#include "board.h"

int main() {
    system("clear");
    Board manBoard;
    Board computerBoard;

    //manBoard.addShipsManual();
    computerBoard.addShipRandom();
    computerBoard.viewBoardShip();
    
}