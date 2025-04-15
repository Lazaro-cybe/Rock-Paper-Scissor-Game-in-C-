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

int main() {
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    char playAgain;
    
    // Seed the random number generator
    srand(time(0));
    
    cout << "=== Rock Paper Scissors Game ===\n";
    cout << "Rules:\n";
    cout << "- Rock beats Scissors\n";
    cout << "- Paper beats Rock\n";
    cout << "- Scissors beat Paper\n\n";
    
    do {
        cout << "\nChoose your move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;
        
        // Validate input
        while (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin >> userChoice;
        }
        
        // Computer makes random choice (1-3)
        computerChoice = rand() % 3 + 1;
        
        cout << "\nYou chose: " << getChoiceName(userChoice) << endl;
        cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

   
        // Determine the winner
        int result = determineWinner(userChoice, computerChoice);
        
        if (result == 0) {
            cout << "It's a tie!\n";
        } 
        else if (result == 1) {
            cout << "You win! " << getChoiceName(userChoice) << " beats " 
                 << getChoiceName(computerChoice) << ".\n";
            userScore++;
        } 
        else {
            cout << "Computer wins! " << getChoiceName(computerChoice) << " beats " 
                 << getChoiceName(userChoice) << ".\n";
            computerScore++;
        }
        
        // Display current score
        cout << "\nCurrent Score:\n";
        cout << "You: " << userScore << " | Computer: " << computerScore << endl;
        
        // Ask to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        
    } while (tolower(playAgain) == 'y');

 // Final score and message
    cout << "\n=== Final Score ===\n";
    cout << "You: " << userScore << " | Computer: " << computerScore << endl;
    
    if (userScore > computerScore) {
        cout << "Congratulations! You won the game!\n";
    } 
    else if (computerScore > userScore) {
        cout << "Computer won the game. Better luck next time!\n";
    } 
    else {
        cout << "The game ended in a tie!\n";
    }
    
    cout << "\nThanks for playing!\n";
    
    return 0;
}
