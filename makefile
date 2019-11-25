###
### @file - lab9_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for Lab 9 - Queues and Stacks

#
# Qeueus and Stacks
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

main: main.o menu.o inputValidation.o randomNum.o drivers.o palindrome.o queueBuffer.o
	$(CXX) $(CFLAGS) -g main.o menu.o inputValidation.o randomNum.o drivers.o palindrome.o queueBuffer.o -o queuesAndStacks

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CFLAGS) -c menu.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	$(CXX) $(CFLAGS) -c inputValidation.cpp

randomNum.o: randomNum.cpp randomNum.hpp
	$(CXX) $(CFLAGS) -c randomNum.cpp

drivers.o: drivers.cpp drivers.hpp
	$(CXX) $(CFLAGS) -c drivers.cpp

palindrome.o: palindrome.cpp palindrome.hpp
	$(CXX) $(CFLAGS) -c palindrome.cpp

queueBuffer.o: queueBuffer.cpp queueBuffer.hpp
	$(CXX) $(CFLAGS) -c queueBuffer.cpp