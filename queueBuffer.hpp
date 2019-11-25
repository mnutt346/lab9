#ifndef QUEUEBUFFER_HPP
#define QUEUEBUFFER_HPP

#include <queue>

void queueBuffer(int, int, int, std::queue<int> &);

void printQueue(std::queue<int>);

void printAverageLength(int, double &, std::queue<int>);

#endif