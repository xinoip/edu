#ifndef Basics_h
#define Basics_h

#include <iostream>

/**
 * This class is just a way to access general functions
 * 
 * I would use namespaces instead making a 'static' class for accessing functions.
 * But it is not covered yet in class so i used this instead.
 */
class BasicUtils
{
public:
    /**
     * Prompt user to get safe input between [start,end]
     * start and end included
     * 
     * @params bounds
     * @return input [int]
     */
    static int getIntInput(int start, int end);

    /**
     * Swap two integer memory spaces
     * 
     * @params integers
     */
    static void swap(int *a, int *b);

    /**
     * Return maximum of given integers
     * 
     * @params integers
     */
    static int max4(int a, int b, int c, int d);

    /**
     * Return random integer between min and max.
     * Inclusive.
     * 
     * @params bounds
     * @return [int] between [min, max]
     */
    static int randBetween(int min, int max);

    static char inverseMove(char c);

private:
    /**
     * This class is just a way to access general functions
     * It should not be instanced!
     */
    BasicUtils();
};

#endif