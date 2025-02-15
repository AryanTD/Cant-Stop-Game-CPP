// ===============================================================
// Can't Stop Board Game          File: Player.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Player.hpp"
//-----------------------------------------------------------------
bool Player::takenColors[4] = {false, false, false, false}; // Initialize player color tracking
vector<string> Player::takenNames = {};  // Initialize player name tracking

Player::Player(const string& playerName, ECcolor playerColor)
               : name(playerName), color(playerColor), score(0) {
    string lowerName = toLowerCase(playerName);
    
    // Check if name is taken **before storing**
    if (isNameTaken(lowerName)) {
        fatal("This player name is already taken! Choose another.");
    }

    // Check if color is taken
    int colorIndex = (int)(playerColor) - 1;
    if (colorIndex < 0 || colorIndex >= 4 || takenColors[colorIndex]) {
        fatal("Color already taken or invalid! Choose a different color.");
    }

    // Assign values only after validation
    takenNames.push_back(lowerName);
    takenColors[colorIndex] = true;
}

//-----------------------------------------------------------------
// Get the tile color of the player.
ECcolor Player::getColor() const { return color; }

//-----------------------------------------------------------------
// Get the score of the player.
int Player::getScore() const { return score; }

//-----------------------------------------------------------------
// Check if player has won the column.
bool Player::wonColumn(int colNum){
    if (score<3){
        scoreboard[score] = colNum; // store the score in the next available column
        score += 1;
        return (score == 3);
    }
    return false;
}

//-----------------------------------------------------------------
// Print the player name, tile color and score.
ostream& Player::print(ostream& os) const {
    os <<"Player Name: " << name
    <<"\nColor: " <<" \t" <<colorNames[(int)(color)]
    <<"\nScore: " <<score <<endl;
    return os;
}

//-----------------------------------------------------------------
// Check if a color is already taken
bool Player::isColorTaken(ECcolor playerColor) {
    int colorIndex = (int)(playerColor) - 1;
    return (colorIndex >= 0 && colorIndex < 4) ? takenColors[colorIndex] : true;
}

//-----------------------------------------------------------------
// Check if a name is already taken
bool Player::isNameTaken(const string& playerName) {
    string lowerName = toLowerCase(playerName);
    return find(takenNames.begin(), takenNames.end(), lowerName) != takenNames.end();
}

//-----------------------------------------------------------------
// Reset the taken colors (for a new game)
void Player::resetTakenData() {
    for (int i = 0; i < 4; i++) {
        takenColors[i] = false;
    }
    takenNames.clear();
}

//-----------------------------------------------------------------
// Helper function to convert string to lowercase
string Player::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}
