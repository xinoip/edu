#include <iostream>
#include "NPuzzle.h"
#include "input_enum.h"

int main(int argc, char const *argv[])
{
    srand(time(0));
    NPuzzle puzzle;
    int inputSize;
    if (argc > 1)
    {
        if (!puzzle.readFromFile(argv[1]))
        {
            exit(EXIT_FAILURE);
        };
    }
    else
    {
        std::cout << "Please enter the problem size: ";
        inputSize = BasicUtils::getIntInput(3, 9);
        puzzle.setSize(inputSize, inputSize);        
        puzzle.shuffle(10);
        std::cout << "\n\nYou can change number of shuffles in NPuzzle.h\n";
    }
    
    // initial print
    std::cout << "Your initial board is\n\n";
    puzzle.print();

    // game loop
    Input input;
    char fileNameInput[100];
    while (true)
    {
        input = InputUtils::getInput();
        std::cout << "\n";

        switch (input)
        {
        case Input::intelligent:
            puzzle.moveIntelligent();
            break;

        case Input::instantSolve:
            puzzle.solvePuzzle();
            break;

        case Input::shuffle:
            puzzle.shuffle(10);
            break;

        case Input::showReport:
            puzzle.printReport();
            break;

        case Input::loadFromFile:
            std::cout << "Enter the file name for loading board: ";
            std::cin >> fileNameInput;
            puzzle.readFromFile(fileNameInput);
            std::cout << "\n\n";
            break;

        case Input::saveToFile:
            std::cout << "Enter the file name for saving board: ";
            std::cin >> fileNameInput;
            puzzle.writeToFile(fileNameInput);
            std::cout << "\n\n";
            break;

        case Input::quit:
            std::cout << "Exiting..\n";
            return 0;
            break;

        case Input::up:
        case Input::down:
        case Input::left:
        case Input::right:
            puzzle.move(InputUtils::convertInputToChar(input));
            break;

        case Input::invalid:
            std::cout << "Invalid input!\n";
            break;

        default:
            std::cerr << "INPUT_ERR\n";
            break;
        }

        puzzle.print();

    }

    std::cout << "\n\nYou win!\n";

    exit(EXIT_SUCCESS);
}