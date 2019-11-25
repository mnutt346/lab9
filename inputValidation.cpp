/**************************************************************************************
** Program name: inputValidation.cpp
** Author: Michael Nutt
** Date: 11/25/2019
** Description: Definitions of the convertInputToInt and isIntegerInput functions.
** The convertInputToInt function gets the input from the user and determines wheter
** that input is a positive integer. If not, the function continues to loop until the
** user submits a positive integer.
**************************************************************************************/

#include <iostream>
#include "inputValidation.hpp"

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/* Summary: Determines whether a given input is an integer.
 * Param: string input -> the input string provided by the user
 * Return: A boolean value representing whether the user input is an integer
 */
bool isIntegerInput(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }

    return true;
}

/* Summary: Attempts to convert user input to an integer. If unsuccessful,
 * prompts the user to enter a new value as a positive integer.
 * Param: N/A
 * Return: The user input converted to an integer.
 */
int convertInputToInt()
{
    string input;

    int integerInput;

    do
    {
        getline(cin, input);
        // Iterate through input string and remove whitespace.
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                input.erase(i, 1);
            }
        }

        if (!isIntegerInput(input))
        {
            cout << "Invalid input. Please enter inputs as positive integers." << endl;
        }
    } while (!isIntegerInput(input));

    integerInput = atoi(input.c_str());

    return integerInput;
}

/* Summary: Checks if the input is an alpha-numeric string of appropriate length.
 * Param: N/A
 * Return: Boolean value representing whether the input is a valid string.
 * Algorithm found at: https://stackoverflow.com/questions/52303608/validate-string-input-in-c-for-letters-and-spaces-only
 */
bool isAlphaNumInput(const string &input)
{
    const int MAX_LENGTH = 50;
    const int MIN_LENGTH = 1;

    if (input.length() > MAX_LENGTH || input.length() < MIN_LENGTH)
    {
        return false;
    }

    for (const char character : input)
    {
        if (!isalpha(character) && !isspace(character) && !isdigit(character))
        {
            return false;
        }
    }
    return true;
}