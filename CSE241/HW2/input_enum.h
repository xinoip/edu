#ifndef InputEnum_h
#define InputEnum_h

#include <iostream>

/**
 * Available inputs
 */
enum class Input
{
    up,
    down,
    left,
    right,
    intelligent,
    shuffle,
    quit,
    instantSolve,
    loadFromFile,
    saveToFile,
    showReport,
    invalid,
};

/**
 * Prompt user and get an input
 * 
 * @return [Input] gotten input
 */
Input getInput();

/**
 * Print passed input with their names
 * 
 * @param d [Input] input that will print
 */
void printInput(Input d);

#endif