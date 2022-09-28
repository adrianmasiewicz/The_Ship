#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <string>
#include "mastship.h"

class Board {
private:
    MastShip singleMasters[4] = {1, 1, 1, 1};
    MastShip twoMasters[3] = {2, 2, 2};
    MastShip threeMasters[2] = {3, 3};
    MastShip fourMasters [1]= {4};

    enum charShip {
        ship,
        point,
        destroyedShip,
        empty
    };
    charShip mapShip[10][10];

    std::string numerMaster[4] = {
        "First-Mast",
        "Second-Mast",
        "Third-Mast",
        "Fourth-Mast"};

public:
    Board();
    ~Board();

    void addShipsManual();
    void addShipRandom();
    void viewBoardShip() const;
    void viewThisPlace(int vertical, int horizontal) const;
    void replaceShipPoints();
    void deletePoints();
    bool insertMasters(int masters = 1);
    bool insertSingleM();
    bool insertTwoM();
    bool insertThreeM();
    bool insertFourM();
    bool checkFree(char a, int value);
    bool checkPointNeighbor(char a, int value);
    void setShip(char a, int value);
    void setPoint(char a, int value);
    int checkAvailable(MastShip array[], int number);
    int replaceCharInt(char take);
};

#endif