#include <iostream>
#include <string>
#include <queue>
#include "drivers.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include "queueBuffer.hpp"
#include "palindrome.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

void runProgram()
{
    const int MIN_ROUNDS = 1;
    const int MAX_ROUNDS = 100;
    const int MIN_PERCENT = 0;
    const int MAX_PERCENT = 100;

    cout << "Welcome to the Stack and Queue STL program." << endl;

    // Prompt user for number of rounds to simulate
    string roundsOption = "the number of rounds you would like to simulate";
    int totalRounds = gameMenuRange(roundsOption, MIN_ROUNDS, MAX_ROUNDS);

    // Prompt the user for the chance that a randomly generated number will be placed at the end of the buffer
    string addPercentPrompt = "an integer to represent the probability that a randomly generated number will be placed \nat the end of the buffer";
    int addProbability = gameMenuRange(addPercentPrompt, MIN_PERCENT, MAX_PERCENT);

    // Prompt the user for the chance that a number at the front of the buffer will be removed
    string removePercentPrompt = "an integer to represent the probability that the front of the buffer will be removed";
    int removeProbability = gameMenuRange(removePercentPrompt, MIN_PERCENT, MAX_PERCENT);

    queue<int> buffer;

    queueBuffer(totalRounds, addProbability, removeProbability, buffer);

    // Prompt the user to enter a string to be converted to a palindrome
    string userInput;

    cout << endl
         << "Now we are going to create a palindrome!" << endl
         << "Please enter a string, and the program will turn it in to a palindrome." << endl;

    getline(cin, userInput);

    while (!isAlphaNumInput(userInput))
    {
        cout << endl
             << "Invalid input. Please enter only alpha-numeric characters." << endl;

        getline(cin, userInput);
    }

    palindrome(userInput);
}