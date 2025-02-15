//=======================================================================
// Project: Can't Stop Board Game        File: main.cpp
// Author:  Ashish Khadka and Aryan Tandon  Copyright: 2025
// ======================================================================
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "enums.hpp"
#include "Column.hpp"
// ----------------------------------------------------------------------
void testColumn(ofstream& outputFile);

int main(int argc, const char * argv[]) {
    banner();
    srand(int(time(nullptr))); // Seed the random number generator once
    ofstream outputFile("test_output.txt"); // Open output file
    if (outputFile.is_open()) {
        testColumn(outputFile);
        outputFile.close(); // Close the file
        cout << "Test results written to test_output.txt\n";
    } else {
        cout << "Error opening test_output.txt\n";
    }
    bye();
}
