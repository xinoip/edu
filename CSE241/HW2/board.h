#ifndef Board_h
#define Board_h

#include <fstream>
#include <cstdlib>
#include "basics.h"
#include "input_enum.h"

/**
 * The Board Struct
 * arr holds the values in 1D array
 * dimension is one of the edges
 * size is dimension * dimension
 */
typedef struct
{
    int arr[9][9];
    int width, height;
    int emptyTileRow, emptyTileCol;
    int moves;
} Board;

/**
 * Initialize the given board with data from given file.
 * Fill with data from given file.
 * 
 * @param *board [Board] pointer
 * @param *fileName [String] file to load
 * @return [bool] was it successful?
 */
bool loadBoard(Board *board, const char *fileName);

/**
 * Save the current board to given fileName.
 * 
 * @param *board [Board] pointer
 * @param *fileName [String] file to save
 */
void saveBoard(Board *board, const char *fileName);

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
bool moveEmptyCell(Board *board, Input input, MessageMode messageMode);

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
Input aiMove(Board *board, Input lastMove);

/**
 * Solve the board with branch and bound solution and print moves
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard(Board *board);

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