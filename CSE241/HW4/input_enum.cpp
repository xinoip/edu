#include "./input_enum.h"

/**
 * Prompt user and get an input
 * 
 * @return [Input] gotten input
 */
Input InputUtils::getInput()
{
    char input = 0;
    std::cout << "Your move: ";
    std::cin >> input;
    switch (input)
    {
    case 'L':
        return Input::left;
        break;
    case 'R':
        return Input::right;
        break;
    case 'U':
        return Input::up;
        break;
    case 'D':
        return Input::down;
        break;
    case 'I':
        return Input::intelligent;
        break;
    case 'S':
        return Input::shuffle;
        break;
    case 'Q':
        return Input::quit;
        break;
    case 'V':
        return Input::instantSolve;
        break;
    case 'Y':
        return Input::loadFromFile;
        break;
    case 'E':
        return Input::saveToFile;
        break;
    case 'T':
        return Input::showReport;
        break;
    default:
        return Input::invalid;
        break;
    }
}

/**
 * Print passed input with their names
 * 
 * @param d [Input] input that will print
 */
void InputUtils::printInput(Input d)
{
    switch (d)
    {
    case Input::up:
        std::cout << "up";
        break;
    case Input::down:
        std::cout << "down";
        break;
    case Input::left:
        std::cout << "left";
        break;
    case Input::right:
        std::cout << "right";
        break;

    default:
        break;
    }
}

char InputUtils::convertInputToChar(Input d)
{
    switch (d)
    {
    case Input::up:
        return 'U';
        break;
    case Input::down:
        return 'D';
        break;
    case Input::left:
        return 'L';
        break;
    case Input::right:
        return 'R';
        break;

    default:
        break;
    }

    std::cerr << "convertInputToChar Error!\n";
    return 'U';
}