// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Dice.hpp"
#include "tools.hpp"
#include "Player.hpp"
//-----------------------------------------------------------------

// Helper function to roll and print dice
void rollAndPrint(Dice& dice, ofstream& testOutput, const string& testName) {
    testOutput << testName << endl;
    dice.roll();
    testOutput << "Rolled: " << dice << endl;
    testOutput << "-------------------------" << endl;
}

void unitDice() {
    // Open the test output file in append mode
    ofstream testOutput("test_output.txt", ios::app);

    if (!testOutput) {
        cerr << "Error opening test output file: test_output.txt" << endl;
        return;
    }

    // Test 1: Default Constructor (1 Die)
    {
        Dice dice1;  // Default constructor (1 die)
        rollAndPrint(dice1, testOutput, "Test 1: Rolling 1 die (default constructor)");
    }

    // Test 2: Constructor with 2 Dice
    {
        Dice dice2(2);  // Constructor with 2 dice
        rollAndPrint(dice2, testOutput, "Test 2: Rolling 2 dice");
    }
    
    // Test 3: Constructor with 3 Dice
    {
        Dice dice3(3);  // Constructor with 3 dice
        rollAndPrint(dice3, testOutput, "Test 3: Rolling 3 dice");
    }
    
    // Test 4: Constructor with 4 Dice
    {
        Dice dice4(4);  // Constructor with 4 dice
        rollAndPrint(dice4, testOutput, "Test 4: Rolling 4 dice");
    }

    // Test 5: Constructor with 5 Dice
    {
        Dice dice5(5);  // Constructor with 5 dice
        rollAndPrint(dice5, testOutput, "Test 5: Rolling 5 dice");
    }
    
    // Test 6: Constructor with 6 Dice
    {
        Dice dice6(6);  // Constructor with 5 dice
        rollAndPrint(dice6, testOutput, "Test 6: Rolling 6 dice");
    }
    
    
    // Test 7: Edge Case – 0 Dice (Invalid Input)
    {
        Dice dice6(0);  // Constructor with 0 dice
        rollAndPrint(dice6, testOutput, "Test 6: Rolling 0 dice");
    }
}

string getPlayerName() {
    string name;
    while (true) {
        cout << "Enter player name (no spaces): ";
        getline(cin, name);  // Read the full line

        // Remove spaces from the name
        name.erase(remove(name.begin(), name.end(), ' '), name.end());
        if (Player::isNameTaken(name)) {
            fatal ("This name is already taken! Choose another.\n");
        }
        // Check if the name is empty after removing spaces
        if (name.empty()) {
            cout << "Invalid name! The name cannot be empty or contain only spaces.\n";
        } else {
            break;  // Valid name, exit the loop
        }
    }
    return name;
}

//-----------------------------------------------------------------
// Function to get a valid ECcolor input
ECcolor getColorFromUser() {
    char choice;
    while (true) {
        cout << "Select a color (B = Blue, G = Green, Y = Yellow, O = Orange): ";
        cin >> choice;
        
        // Convert to uppercase to handle lowercase input
        choice = toupper(choice);
        ECcolor selectedColor = ECcolor::Error;
        // Switch statement to return the correct enum
        switch (choice) {
            case 'B': return ECcolor::Blue;
            case 'G': return ECcolor::Green;
            case 'Y': return ECcolor::Yellow;
            case 'O': return ECcolor::Orange;
            default:
                // Invalid input statement
                cout << "Invalid choice! Please enter B, G, Y, or O.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        
        if (!Player::isColorTaken(selectedColor)) {
            return selectedColor;
        } else {
          cout << "This color is already taken. Choose another.\n";
        }
    }
}

//-----------------------------------------------------------------
// Test for the Player class
void testPlayer(ofstream& outputFile) {
    // Open the test output file in append mode
    cout << "Starting Player class unit tests...\n";
    
    // Get player names from user input
    string name1 = getPlayerName();  // Get Player 1's name
    string name2 = getPlayerName();  // Get Player 2's name
    ECcolor color1 = getColorFromUser();
    ECcolor color2 = getColorFromUser();

    // Create Player instances
    Player player1(name1, color1);
    Player player2(name2, color2);
    cout<< player1;
    cout<< player2;

    // Test getColor()
    outputFile << "Testing getColor():\n";
    if (player1.getColor() == ECcolor::Orange) {
        outputFile << "Player 1 color is correct (Orange).\n";
    } else {
        outputFile << "Player 1 color is incorrect.\n";
    }
    if (player2.getColor() == ECcolor::Blue) {
        outputFile << "Player 2 color is correct (Blue).\n";
    } else {
        outputFile << "Player 2 color is incorrect.\n";
    }

    // Test getScore() (should be 0 initially)
    outputFile << "\nTesting getScore():\n";
    if (player1.getScore() == 0) {
        outputFile << "Player 1 score is correct (0).\n";
    } else {
        outputFile << "Player 1 score is incorrect.\n";
    }
    if (player2.getScore() == 0) {
        outputFile << "Player 2 score is correct (0).\n";
    } else {
        outputFile << "Player 2 score is incorrect.\n";
    }

    // Test wonColumn()
    outputFile << "\nTesting wonColumn():\n";
    if (player1.wonColumn(3) == false) {  // 1st column
        outputFile << "Player 1 column 3 captured correctly.\n";
    } else {
        outputFile << "Player 1 column 3 capture failed.\n";
    }
    if (player1.wonColumn(5) == false) {  // 2nd column
        outputFile << "Player 1 column 5 captured correctly.\n";
    } else {
        outputFile << "Player 1 column 5 capture failed.\n";
    }
    if (player1.wonColumn(7) == true) {   // 3rd column → should return true (win condition)
        outputFile << "Player 1 captured all columns and won!\n";
    } else {
        outputFile << "Player 1 failed to win.\n";
    }

    // Test operator<< (output test)
    outputFile << "\nTesting operator<< (printing players):\n";
    outputFile << "Player 1:\n" << player1;
    outputFile << "\nPlayer 2:\n" << player2;
    outputFile << "\nAll Player tests completed!" << endl;
}
