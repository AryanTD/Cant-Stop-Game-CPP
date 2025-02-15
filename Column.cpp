// ===============================================================
// Can't Stop Board Game          File: Column.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Column.hpp"
//-----------------------------------------------------------------
const int Column::columnLengths[13] = { 0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3 };

Column::Column (int colNum) : columnNumber(colNum), state(ECstate::Available){
    if (colNum < 2 || colNum > 12){
        throw invalid_argument("Column number must be between 2 and 12");
    }
}

//-----------------------------------------------------------------
// Returns the current state of the column
ECstate Column::getState() const { return state; }

//-----------------------------------------------------------------
// Prints the column state and contents
void Column::print() const {
    cout << columnNumber << " " << stateNames[(int)(state)];
    for (int i = 1; i <= columnLengths[columnNumber]; i++) {
        cout << "  ";
        for (int j = 0; j < 5; j++) {
            if (markers[j] == i) {
                cout << (j == 0 ? 'T' : colorNames[j][0]);
            }
            else cout << "-";
        }
        cout << "  ";
    }
    cout << endl;
}

//-----------------------------------------------------------------
// Overload operator <<
ostream& operator<<(ostream& os, const Column& col) {
    col.print();
    return os;
}

//-----------------------------------------------------------------
// Start a tower for a player
bool Column::startTower(Player* player) {
    if (state == ECstate::Captured) return false;
    ECcolor playerColor = player->getColor();
    
    int playerIndex = (int)(playerColor);
    markers[0] = (markers[playerIndex] == 0) ? 1 : markers[playerIndex] + 1;
    
    if (markers[playerIndex] > 0) {
        markers[playerIndex]++;
    } else {
        markers[playerIndex] = 1;
    }
    
    if (markers[playerIndex] >= columnLengths[columnNumber]) {
        state = ECstate::Pending;
    }
    return true;
}

//-----------------------------------------------------------------
// Moves tower forward
bool Column::move() {
    if (state == ECstate::Captured) return false;
    for (int& marker : markers) {
        if (marker > 0 && marker < columnLengths[columnNumber]) {
            marker++;
        }
        
        if (marker == columnLengths[columnNumber]) {
            state = ECstate::Pending;
        }
    }
    return true;
}

//-----------------------------------------------------------------
// Stop and replace tower with tile
void Column::stop(Player* player) {
    ECcolor playerColor = player->getColor();
    int playerIndex = (int)(playerColor);
    
    if (markers[0] == 0) return;  // No tower to replace
    markers[playerIndex] = markers[0]; // Convert tower into tile of player's color
    markers[0] = 0;  // Remove the tower
    
    if (markers[playerIndex] > 0) {
        if (state == ECstate::Pending) {
            state = ECstate::Captured;
            player->wonColumn(columnNumber);
        }
    }
}

//-----------------------------------------------------------------
// Reset markers on bust
void Column::bust() {
    // Implementation to be added later
}
