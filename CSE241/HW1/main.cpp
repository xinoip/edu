#include <iostream>
#include <cstdlib>
#include "board.h"

/**
 * Number of shuffles for difficulty of puzzle
 */
const int NUMBER_OF_SHUFFLES = 10;

/**
 * There are two modes for AI
 * 
 * One is STACK_AI which stores the solution as user plays
 * Then backtracks the solution [stack] and makes move
 * 
 * Second is BRANCH_AI which looks for the costs of next moves
 * Makes the least cost move (Branch&Bound)
 */
const int STACK_AI = 1;
const int BRANCH_AI = 2;

int main()
{
    // random seed and board
    srand(time(0));
    //Board *board = new Board;
    Board *board = (Board *)malloc(sizeof(Board));
    int inputSize;
    int algorithmInput;

    // get dimension
    std::cout << "Please enter the problem size: ";
    inputSize = getIntInput(3, 9);

    // init and mix board
    initBoard(board, inputSize);
    mixBoard(board, NUMBER_OF_SHUFFLES);

    // get algorithm selection
    std::cout << "\nThere are 2 available algorithms for intelligent move:\n";
    std::cout << "1 - Stack solution (solves %100)\n";
    std::cout << "2 - Branch&Bound solution (without backtracking, so on stuck cases it may not be able to solve %100)\n";
    std::cout << "Please select the algorithm: ";
    algorithmInput = getIntInput(1, 2);

    // initial print
    std::cout << "\n\nYou can change number of shuffles in main.cpp\n";
    std::cout << "Your initial random board is\n\n";
    printBoard(board);

    // game loop
    Input input, aiInput, lastMove;
    while (checkIncorrects(board) > 0)
    {
        input = getInput();
        if (input != Input::invalid)
        { // input valid
            if (input == Input::intelligent)
            { // ai input
                if (algorithmInput == STACK_AI)
                { // stack_ai
                    aiInput = aiMove(board);
                }
                else if (algorithmInput == BRANCH_AI)
                { // branch_ai
                    aiInput = aiMove2(board, lastMove);
                    lastMove = aiInput;
                }

                moveEmptyCell(board, aiInput, MessageMode::ai, true);
            }
            else
            { // player input
                moveEmptyCell(board, input, MessageMode::player, true);
            }
            if (input == Input::quit)
            { // quit
                std::cout << "Quiting..\n";
                return 0;
            }
            if (input == Input::shuffle)
            { // shuffle
                std::cout << "Shuffling..\n";
                for (int i = 0; i < board->size; i++)
                {
                    board->arr[i] = i + 1;
                }
                board->arr[board->size - 1] = EMPTY;
                board->emptyTile = board->size - 1;
                resetStack(&(board->solution));
                mixBoard(board, NUMBER_OF_SHUFFLES);
            }
            if (input == Input::instantSolve)
            { // instant solve [P] key
                if (algorithmInput == STACK_AI)
                { // stack_ai
                    int aiRes = solveBoard(board);
                    std::cout << "AI solved the board in " << aiRes << " moves!\n";
                }
                else if (algorithmInput == BRANCH_AI)
                { // branch_ai
                    int aiRes = solveBoard2(board);
                    std::cout << "AI tried to solve the board in " << aiRes << " moves!\n";
                    if (aiRes > 1000)
                    {
                        std::cout << "AI failed to solve the board!\n";
                    }
                }
            }

            printBoard(board);
        }
        else
        { // invalid input
            std::cout << "Invalid input!\n";
        }
    }

    std::cout << "\n\nYou win!\n";

    exit(EXIT_SUCCESS);
}