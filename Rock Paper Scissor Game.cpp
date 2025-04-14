#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to convert choice number to string
string getChoiceName(int choice) {
    switch(choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}

// Function to determine the winner
int determineWinner(int userChoice, int computerChoice) {
    // Tie game
    if (userChoice == computerChoice) {
        return 0;
    }
    
    // User wins scenarios
    if ((userChoice == 1 && computerChoice == 3) || // Rock beats Scissors
        (userChoice == 2 && computerChoice == 1) || // Paper beats Rock
        (userChoice == 3 && computerChoice == 2)) {  // Scissors beat Paper
        return 1;
    }
    
    // Computer wins if not user wins and not tie
    return -1;
}