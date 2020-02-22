#include <iostream>
#include <cstdlib>
#include "board.h"

/**
 * Number of shuffles for difficulty of puzzle
 */
const int NUMBER_OF_SHUFFLES = 15;

int main(int argc, char const *argv[])
{
    srand(time(0));
    Board *board = (Board *)malloc(sizeof(Board));
    int inputSize;

    if (argc > 1)
    { // load from file
        if (!loadBoard(board, argv[1]))
        {
            exit(EXIT_FAILURE);
        };
    }
    else
    { // start like HW1
        // get dimension
        std::cout << "Please enter the problem size: ";
        inputSize = getIntInput(3, 9);
        // init and mix board
        initBoard(board, inputSize);
        mixBoard(board, NUMBER_OF_SHUFFLES);
        std::cout << "\n\nYou can change number of shuffles in main.cpp\n";
    }

    // initial print
    std::cout << "Your initial board is\n\n";
    printBoard(board);

    // game loop
    Input input, aiInput, lastMove;
    int aiRes;
    char fileNameInput[100];
    while (checkIncorrects(board) > 0)
    {
        input = getInput();
        std::cout << "\n";

        switch (input)
        {
        case Input::intelligent:
            aiInput = aiMove(board, lastMove);
            lastMove = aiInput;

            moveEmptyCell(board, aiInput, MessageMode::ai);
            board->moves++;
            break;

        case Input::instantSolve:
            aiRes = solveBoard(board);
            std::cout << "AI tried to solve the board in " << aiRes << " moves!\n";
            if (aiRes > AI_LIMIT)
            {
                std::cout << "AI failed to solve the board!\n";
            }
            break;

        case Input::shuffle:
            std::cout << "Shuffling..\n";
            mixBoard(board, NUMBER_OF_SHUFFLES);
            board->moves += NUMBER_OF_SHUFFLES;
            break;

        case Input::showReport:
            std::cout << board->moves << " moves done and no solution found!\n";
            break;

        case Input::loadFromFile:
            std::cout << "Enter the file name for loading board: ";
            std::cin >> fileNameInput;
            loadBoard(board, fileNameInput);
            std::cout << "\n\n";
            break;

        case Input::saveToFile:
            std::cout << "Enter the file name for saving board: ";
            std::cin >> fileNameInput;
            saveBoard(board, fileNameInput);
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
            moveEmptyCell(board, input, MessageMode::player);
            board->moves++;
            break;

        case Input::invalid:
            std::cout << "Invalid input!\n";
            break;

        default:
            std::cerr << "INPUT_ERR\n";
            break;
        }

        printBoard(board);

    }

    std::cout << "\n\nYou win!\n";

    exit(EXIT_SUCCESS);
}