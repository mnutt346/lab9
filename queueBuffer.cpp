#include <queue>
#include <iostream>
#include <iomanip>
#include "queueBuffer.hpp"
#include "randomNum.hpp"

using std::cout;
using std::endl;
using std::fixed;
using std::queue;
using std::setprecision;

void queueBuffer(int rounds, int addPercent, int removePercent, queue<int> &buffer)
{
    const int MIN_RAND = 1;
    const int MAX_RAND = 1000;
    const int MIN_PERCENT = 1;
    const int MAX_PERCENT = 100;

    for (int i = 1; i <= rounds; i++)
    {
        cout << endl
             << "----- Round " << i << " -----" << endl;

        // Generate a random number to potentially be added to the buffer
        int randomElement = randomNum(MIN_RAND, MAX_RAND);

        // If addPercent is >= a random number from 1 - 100:
        if (addPercent >= randomNum(MIN_PERCENT, MAX_PERCENT))
        {
            cout << "Adding " << randomElement << " to the buffer." << endl;
            // Add the random number
            buffer.push(randomElement);
        }
        else
        {
            cout << "No new value added to the buffer this round." << endl;
        }

        // If removePercent >= a random number from 1 - 100 and the buffer is not empty:
        if (removePercent >= randomNum(MIN_PERCENT, MAX_PERCENT) && !buffer.empty())
        {
            cout << "Removing the first number from the buffer." << endl;
            buffer.front();
            buffer.pop();
        }
        else
        {
            cout << "No values removed this round." << endl;
        }

        // Print the current buffer
        printQueue(buffer);

        // Print the current length
        cout << "Buffer length: " << buffer.size() << endl;

        // Print average length;
        double average;
        printAverageLength(i, average, buffer);
    }
}

void printQueue(queue<int> buffer)
{
    cout << "Buffer: ";
    while (!buffer.empty())
    {
        // Print the first element in buffer
        cout << buffer.front() << " ";
        // Pop the first element in buffer
        buffer.pop();
    }
    cout << endl;
}

void printAverageLength(int currentRound, double &average, queue<int> buffer)
{

    cout << "Average length: " << fixed << setprecision(2);
    // If it's the first round, the size is just the current size of the queue
    if (currentRound <= 1)
    {
        average = buffer.size();
        cout << average;
    }
    else
    {
        average = (average * (currentRound - 1) + buffer.size()) / (currentRound);
        cout << average;
    }
    cout << endl;
}