#ifndef Basics_h
#define Basics_h

#include <iostream>

/**
 * Representing empty tile
 */
const int EMPTY = -1;

/**
 * Used for printing meaningful messages to user like:
 * `Player did foo...`
 * `Ai done something...`
 * `` (dont print any message)
 */
enum class MessageMode
{
    player,
    ai,
    none,
};

/**
 * Prompt user to get safe input between [start,end]
 * start and end included
 * 
 * @params bounds
 * @return input [int]
 */
int getIntInput(int start, int end);

/**
 * Swap two integer memory spaces
 * 
 * @params integers
 */
void swap(int *a, int *b);

/**
 * Find the minimum of given params
 * 
 * @params integers
 * @return [int] minimum of params
 */
int min4(int a, int b, int c, int d);

/**
 * Return random integer between min and max.
 * Inclusive.
 * 
 * @params bounds
 * @return [int] between [min, max]
 */
int randBetween(int min, int max);

/**
 * Print message with some modes
 * 
 * output: "Intelligence/You + message"
 * output: none
 * 
 * @params mode [MessageMode] MessageMode enum class
 * @params msg [String] message you want to display
 */
void printMessageMode(MessageMode mode, const char *msg);

#endif