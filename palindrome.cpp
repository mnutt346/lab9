#include <string>
#include <iostream>
#include <stack>
#include "palindrome.hpp"

using std::cout;
using std::endl;
using std::stack;
using std::string;

void palindrome(string userInput)
{
    stack<char> stackindrome;

    cout << endl
         << "Your palindrome: ";

    for (int i = 0; i < userInput.size(); i++)
    {
        stackindrome.push(userInput[i]);
    }

    cout << userInput;
    while (stackindrome.size())
    {
        cout << stackindrome.top();
        stackindrome.pop();
    }
}