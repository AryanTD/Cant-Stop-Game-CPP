// ================================================================
// Name: Can't Stop Board Game        Feb, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: Column.hpp
// ================================================================
#pragma once
#include "tools.hpp"
#include "Player.hpp"
#include "enums.hpp"
// -----------------------------------------------------------------

class Column{
private:
    static const int columnLengths[13];
    const int columnNumber;
    ECstate state;
    int markers[5] = {0};
    
public:
    Column(int colNum);
    ~Column(){};
    
    ECstate getState() const;
    
    bool startTower(Player* player);
    bool move();
    void stop(Player* player);
    void bust();
    
    void print() const;
    friend ostream& operator<<(ostream& os, const Column& col);
};
