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
 * This class is just a way to access general input functions
 * 
 * I would use namespaces instead making a 'static' class for accessing functions.
 * But it is not covered yet in class so i used this instead.
 */
class InputUtils
{
public:
    /**
     * Prompt user and get an input
     * 
     * @return [Input] gotten input
     */
    static Input getInput();

    /**
     * Print passed input with their names
     * 
     * @param d [Input] input that will print
     */
    static void printInput(Input d);

    /**
     * Converts given input to it's char equivalent
     * for example, Input::up return 'U' 
     * 
     * @param d [Input] input that will be converted
     */
    static char convertInputToChar(Input d);

private:
    /**
     * This class is just a way to access general input functions
     * It should not be instanced!
     */
    InputUtils();
};

#endif