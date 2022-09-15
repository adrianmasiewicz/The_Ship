#include "board.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mapShip[i][j] = empty;
        }
    }
}

Board::~Board() {}

void Board::viewBoardShip() const {
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            char temp = 'A';
            cout << "   ";
            for (int i = 0; i < 10; i++) {
                cout << temp++ << " ";
            }
            cout << endl;
        }
        if (i != 9)
            cout << " ";
        cout << i + 1 << " ";
        for (int j = 0; j < 10; j++) {
            viewThisPlace(i, j);
            cout << " ";
        }
        cout << endl;
    }
}

void Board::viewThisPlace(int i, int j) const {
    if (mapShip[i][j] == empty) {
        cout << "_";
    } else if (mapShip[i][j] == ship) {
        cout << "□";
    } else if (mapShip[i][j] == destroyedShip) {
        cout << "X";
    }
}

void Board::setShip(char a, int value) {
    int charNumber = replaceCharInt(a);
    value--;
    mapShip[value][charNumber] = ship;
}

void Board::addShipsManual() {
    while (true) {
        int choose;
        viewBoardShip();
        cout << "Select the ship you want to insert:\n";
        if (checkAvailable(singleMasters, 4))
            cout << "1 - Single-Masters (available: " << checkAvailable(singleMasters, 4) << ")\n";
        if (checkAvailable(twoMasters, 3))
            cout << "2 - Two-Masters (available: " << checkAvailable(twoMasters, 3) << ")\n";
        if (checkAvailable(threeMasters, 2))
            cout << "3 - Three-Masters (available: " << checkAvailable(threeMasters, 2) << ")\n";
        if (checkAvailable(fourMasters))
            cout << "4 - Four-Masters (available: " << checkAvailable(fourMasters) << ")\n";
        cin >> choose;

        if (choose == 1) {
            static int placed = 0;
            if (insertSingleM())
                singleMasters[placed++].addSwim();
        }
        if (choose == 2) {
            static int placed = 0;
            insertTwoM();
            twoMasters[placed++].addSwim();
        }
        if (choose == 3) {
            static int placed = 0;
            insertThreeM();
            threeMasters[placed++].addSwim();
        }
        if (choose == 4) {
            static int placed = 0;
            insertSingleM();
            fourMasters.addSwim();
        }
        system("clear");
    }
}

bool Board::insertSingleM() {
    char boardChar;
    int boardValue;

    do {
        cout << "Enter the place where you want to insert the ship (e.g. A2) or [q] to go back:\n";
        cin >> boardChar;
        if (boardChar == 'q')
            return false;
        cin >> boardValue;

    } while (!checkFree(boardChar, boardValue) && cout << "This place is not available. Choose another place!\n");

    setShip(boardChar, boardValue);
    return true;
}

bool Board::insertTwoM() {
    return true;
}

bool Board::insertThreeM() {
    return true;
}

bool Board::insertFourM() {
    return true;
}

int Board::checkAvailable(MastShip array[], int number) {
    int value = number;
    for (int i = 0; i < number; i++) {
        value -= array[i].checkSwim();
    }
    return value;
}
int Board::checkAvailable(MastShip& ship) {
    return 1;
}

bool Board::checkFree(char boardChar, int vertical) {
    bool free = true;
    int horizontal = replaceCharInt(boardChar);
    vertical--;

    if (mapShip[vertical][horizontal] == ship)
        free = false;
    if (vertical + 1 < 10 && mapShip[vertical + 1][horizontal] == ship)
        free = false;
    if (vertical - 1 >= 0 && mapShip[vertical - 1][horizontal] == ship)
        free = false;
    if (horizontal + 1 < 10 && mapShip[vertical][horizontal + 1] == ship)
        free = false;
    if (horizontal - 1 >= 0 && mapShip[vertical][horizontal - 1] == ship)
        free = false;
    if (vertical + 1 < 10 && horizontal + 1 < 10 && mapShip[vertical + 1][horizontal + 1] == ship)
        free = false;
    if (vertical + 1 < 10 && horizontal - 1 >= 0 && mapShip[vertical + 1][horizontal - 1] == ship)
        free = false;
    if (vertical - 1 >= 0 && horizontal + 1 < 10 && mapShip[vertical - 1][horizontal + 1] == ship)
        free = false;
    if (vertical - 1 >= 0 && horizontal - 1 >= 0 && mapShip[vertical - 1][horizontal - 1] == ship)
        free = false;
    
    return free;
}

int Board::replaceCharInt(char a) {
    int charNumber = -1;

    if (a == 'a' || a == 'A')
        charNumber = 0;
    if (a == 'b' || a == 'B')
        charNumber = 1;
    if (a == 'c' || a == 'C')
        charNumber = 2;
    if (a == 'd' || a == 'D')
        charNumber = 3;
    if (a == 'e' || a == 'E')
        charNumber = 4;
    if (a == 'f' || a == 'F')
        charNumber = 5;
    if (a == 'g' || a == 'G')
        charNumber = 6;
    if (a == 'h' || a == 'H')
        charNumber = 7;
    if (a == 'i' || a == 'I')
        charNumber = 8;
    if (a == 'J' || a == 'j')
        charNumber = 9;

    return charNumber;
}