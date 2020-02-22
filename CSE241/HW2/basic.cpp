#include "./basics.h"

/**
 * Swap two integer memory spaces
 * 
 * @params integers
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Find the minimum of given params
 * 
 * @params integers
 * @return [int] minimum of params
 */
int min4(int a, int b, int c, int d)
{
    if (a <= b && a <= c && a <= d)
        return a;
    else if (b <= a && b <= c && b <= d)
        return b;
    else if (c <= a && c <= b && c <= d)
        return c;
    else
        return d;
}

/**
 * Return random integer between min and max.
 * Inclusive.
 * 
 * @params bounds
 * @return [int] between [min, max]
 */
int randBetween(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/**
 * Print message with some modes
 * 
 * output: "Intelligence/You + message"
 * output: none
 * 
 * @params mode [MessageMode] MessageMode enum class
 * @params msg [String] message you want to display
 */
void printMessageMode(MessageMode mode, const char *msg)
{
    switch (mode)
    {
    case MessageMode::ai:
        std::cout << "Intelligence ";
        break;
    case MessageMode::player:
        std::cout << "You ";
        break;
    case MessageMode::none:
        return;
        break;
    }
    std::cout << msg << std::endl;
}

/**
 * Prompt user to get safe input between [start,end]
 * start and end included
 * 
 * @params bounds
 * @return input [int]
 */
int getIntInput(int start, int end)
{
    bool success = false;
    int input = 0;

    do
    {
        std::cin >> input;
        if (!std::cin.fail())
        {
            if (input >= start && input <= end)
            {
                success = true;
            }
            else
            {
                std::cout << "You can only enter between " << start << " and " << end << "\n";
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "You can only enter a number!\n";
        }

    } while (!success);

    return input;
}
