#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


string getUserChoice() {
    string userChoice;
    cout << "Select your choice (rock, paper, scissors): ";
    cin >> userChoice;
    return userChoice;
}


string determineWinner(const string& userChoice, const string& computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a draw!";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
        return "Congratulations! You are victorious.";
    } else {
        return "The machine has defeated you this time.";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); \

    while (true) {
        string userChoice = getUserChoice();

        string choices[] = {"rock", "paper", "scissors"};
        string computerChoice = choices[rand() % 3];

        cout << "\nYou chose " << userChoice << ", your opponent chose " << computerChoice << ".\n";

        string resultMessage = determineWinner(userChoice, computerChoice);
        cout << resultMessage << endl;


        string playAgain;
        cout << "Do you wish to challenge again? (yes/no): ";
        cin >> playAgain;

        if (playAgain != "yes") {
            cout << "Thank you for playing! Farewell!\n";
            break;
        }
    }

    return 0;
}
