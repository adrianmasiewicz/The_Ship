#ifndef BOARD_H_
#define BOARD_H_

#include "mastship.h"
#include <array>

class Board {
private:
    MastShip singleMasters[4] = {1, 1, 1, 1};
    MastShip twoMasters[3] = {2, 2, 2};
    MastShip threeMasters[2] = {3, 3};
    MastShip fourMasters = 4;

    enum charShip {
        ship,
        destroyedShip,
        empty
    };
    charShip mapShip[10][10];

public:
    Board();
    ~Board();

    void addShipsManual();
    void addShipRandom();
    void viewBoardShip() const;
    void viewThisPlace(int vertical, int horizontal) const;
    bool insertSingleM();
    bool insertTwoM();
    bool insertThreeM();
    bool insertFourM();
    void setShip(char a, int value);
    bool checkFree(char a, int value);
    int checkAvailable(MastShip array[], int number);
    int checkAvailable(MastShip& ship);
    int replaceCharInt(char take);
};

#endif