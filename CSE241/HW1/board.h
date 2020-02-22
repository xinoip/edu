#ifndef Board_h
#define Board_h

#include <cstdlib>
#include "basics.h"
#include "stack.h"
#include "input_enum.h"

/**
 * The Board Struct
 * arr holds the values in 1D array
 * dimension is one of the edges
 * size is dimension * dimension
 * 
 * solution is a stack, it holds the best possible route
 *  for stack_ai, for branch_ai we don't use it
 * 
 * if user makes wrong moves it pushes the fixes to stack
 * so we can backtrack if user fails for stack_ai
 */
typedef struct
{
    int *arr;
    int dimension, size;
    int emptyTile;
    stack_t *solution;
} Board;

/**
 * Initialize the given board with given dimensions.
 * Fill with solved end state.
 * 
 * @param *board [Board] pointer
 */
void initBoard(Board *board, int dimension);

/**
 * Mix board [n] times
 * 
 * @param *board [Board] pointer
 * @return [int] number of mixes
 */
void mixBoard(Board *board, int n);

/**
 * Move the empty cell with given input and update board.
 * 
 * @param *board [Board] pointer
 * @param input [Input] enum class
 * @param messageMode [MessageMode] enum class for printings
 * @return [bool] didMoved?
 */
bool moveEmptyCell(Board *board, Input input, MessageMode messageMode, bool checkStack);

/**
 * Find the best move with stack solution
 * 
 * @param *board [Board] pointer
 * @return [Input] found move
 */
Input aiMove(Board *board);

/**
 * Find the best move with branch and bound solution
 * 
 * I used Branch&Bound algorithm.
 * First look for every possible move and calculate `Cost`
 * Cost is `incorrect tiles on the board`
 * Find minimum cost moves, there can exist multiple minimum values
 * If there are multiple minimums, select randomly between minimums
 * Else just select the minimum
 * Then return the decided move
 * 
 * I also store the lastMove of AI because we dont want to go into a loop
 * 
 * @param *board [Board] pointer
 * @param lastInput [Input] ai's last move
 * @return [Input] found move
 */
Input aiMove2(Board *board, Input lastMove);

/**
 * Solve the board with stack solution
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard(Board *board);

/**
 * Solve the board with branch and bound solution and print moves
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard2(Board *board);

/**
 * Checks the incorrect tiles on board.
 * 
 * @param *board [Board] pointer
 * @return [int] number of incorrect tiles
 */
int checkIncorrects(Board *board);

/**
 * Print the given board giving 2 digit spaces to every cell.
 * 
 * @param *board [Board] pointer
 */
void printBoard(Board *board);

#endif