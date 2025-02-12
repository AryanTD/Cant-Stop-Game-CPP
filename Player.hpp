// ================================================================
// Name: Can't Stop Board Game        Jan, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: Player.hpp
// ================================================================
#pragma once
#include "tools.hpp"
#include "enums.hpp"
// -----------------------------------------------------------------
class Player{
private:
    string name;
    ECcolor color;
    int score;
    int scoreboard[3];
    
    static bool takenColors[4]; // Track if colors are used (Index: 0=Orange, 1=Blue, 2=Yellow, 3=Green
    static vector<string> takenNames; // Track used player names
    
public:
    Player(const string& playerName, ECcolor playerColor);
    ~Player(){}
    
//    Accessor functions
    ECcolor getColor() const;
    int getScore() const;
    
//    stores the number of captured columns
    bool wonColumn(int colNum);
    
//    functions to handle name and color chosen by players
    static bool isColorTaken (ECcolor playerColor);
    static bool isNameTaken (const string& playerName);
    static void resetTakenData();
    
//    Print function
    ostream& print(ostream& os) const;
};

//    Overload the output operator
inline ostream& operator<<(ostream& os, Player& player) {
    return player.print(os);
}
