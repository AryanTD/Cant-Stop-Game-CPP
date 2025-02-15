// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "tools.hpp"
#include "Player.hpp"
#include "enums.hpp"
#include "Column.hpp"
//-----------------------------------------------------------------
void testColumn(ofstream& outputFile) {
    outputFile << "Starting Column class unit test...\n";
    Column column1(4);  // Column 4 (length 7)
    Column column2(11); // Column 11 (length 5)
    
    outputFile << "Initial Columns:\n";
    column1.print();
    column2.print();

    Player player1("John",ECcolor::Green);
    Player player2("Randy",ECcolor::Orange);

    outputFile << "\nTesting startTower function...\n";
    if (column1.startTower(&player1)) {
        outputFile << "Player 1 started tower in column 4.\n";
    } else {
        outputFile << "Failed to start tower for Player 1 in column 4.\n";
    }

    if (column2.startTower(&player2)) {
        outputFile << "Player 2 started tower in column 11.\n";
    } else {
        outputFile << "Failed to start tower for Player 2 in column 11.\n";
    }

    column1.print();
    column2.print();

    outputFile << "\nTesting move function...\n";
    if (column1.move()) {
        outputFile << "Moved tower in column 4.\n";
    } else {
        outputFile << "Move failed in column 4.\n";
    }

    if (column2.move()) {
        outputFile << "Moved tower in column 11.\n";
    } else {
        outputFile << "Move failed in column 11.\n";
    }

    column1.print();
    column2.print();

    outputFile << "\nTesting stop function...\n";
    column1.stop(&player1);
    column2.stop(&player2);

    column1.print();
    column2.print();
    
    column2.startTower(&player2);
    column2.move();
    column2.move();
    column2.move();
    column2.print();
    
    outputFile << "Column class unit test completed.\n";
}
