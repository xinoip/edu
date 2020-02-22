#include "./board.h"

/**
 * Mix board [n] times
 * 
 * @param *board [Board] pointer
 * @return [int] number of mixes
 */
void mixBoard(Board *board, int n)
{
    int randomMove;
    bool isMoved = false;
    while (n > 0)
    {
        randomMove = randBetween(0, 3);
        switch (randomMove)
        {
        case 0:
            isMoved = moveEmptyCell(board, Input::up, MessageMode::none, false);
            if (isMoved)
                pushStack(&(board->solution), Input::down);
            break;
        case 1:
            isMoved = moveEmptyCell(board, Input::down, MessageMode::none, false);
            if (isMoved)
                pushStack(&(board->solution), Input::up);
            break;
        case 2:
            isMoved = moveEmptyCell(board, Input::left, MessageMode::none, false);
            if (isMoved)
                pushStack(&(board->solution), Input::right);
            break;
        case 3:
            isMoved = moveEmptyCell(board, Input::right, MessageMode::none, false);
            if (isMoved)
                pushStack(&(board->solution), Input::left);
            break;

        default:
            break;
        }
        if (isMoved)
            n--;
    }
}

/**
 * Move the empty cell with given input.
 * 
 * @param *board [Board] pointer
 * @param input [Input] enum class
 * @param messageMode [MessageMode] enum class for printings
 * @param checkStack [bool] while initing board i dont need to checkStack
 * @return [bool] moveSucces?
 */
bool moveEmptyCell(Board *board, Input input, MessageMode messageMode, bool checkStack)
{
    bool isMoved = false;
    switch (input)
    {
    case Input::left:
        if (board->emptyTile % board->dimension != 0)
        {
            printMessageMode(messageMode, "moved left");
            swap(&board->arr[board->emptyTile], &board->arr[board->emptyTile - 1]);
            board->emptyTile = board->emptyTile - 1;
            if (checkStack)
            {
                if (peekStack(board->solution) == Input::left)
                {
                    popStack(&(board->solution));
                }
                else
                {
                    pushStack(&(board->solution), Input::right);
                }
            }
            isMoved = true;
        }
        break;
    case Input::right:
        if (board->emptyTile % board->dimension != board->dimension - 1)
        {
            printMessageMode(messageMode, "moved right");
            swap(&board->arr[board->emptyTile], &board->arr[board->emptyTile + 1]);
            board->emptyTile = board->emptyTile + 1;
            if (checkStack)
            {
                if (peekStack(board->solution) == Input::right)
                {
                    popStack(&(board->solution));
                }
                else
                {
                    pushStack(&(board->solution), Input::left);
                }
            }
            isMoved = true;
        }
        break;

    case Input::up:
        if (board->emptyTile / board->dimension != 0)
        {
            printMessageMode(messageMode, "moved up");
            swap(&board->arr[board->emptyTile], &board->arr[board->emptyTile - board->dimension]);
            board->emptyTile = board->emptyTile - board->dimension;
            if (checkStack)
            {
                if (peekStack(board->solution) == Input::up)
                {
                    popStack(&(board->solution));
                }
                else
                {
                    pushStack(&(board->solution), Input::down);
                }
            }
            isMoved = true;
        }
        break;

    case Input::down:
        if (board->emptyTile / board->dimension != board->dimension - 1)
        {
            printMessageMode(messageMode, "moved down");
            swap(&board->arr[board->emptyTile], &board->arr[board->emptyTile + board->dimension]);
            board->emptyTile = board->emptyTile + board->dimension;
            if (checkStack)
            {
                if (peekStack(board->solution) == Input::down)
                {
                    popStack(&(board->solution));
                }
                else
                {
                    pushStack(&(board->solution), Input::up);
                }
            }
            isMoved = true;
        }
        break;
    default:
        break;
    }
    return isMoved;
}

Input aiMove(Board *board)
{
    return peekStack(board->solution);
}

Input aiMove2(Board *board, Input lastMove)
{
    // costs for moves
    int rCost, lCost, uCost, dCost, minCost;
    // can move?
    bool moveFlagR, moveFlagL, moveFlagU, moveFlagD;
    // is minimum?
    bool minR = false, minL = false, minU = false, minD = false;

    // FIRST OF CALCULATE COSTS FOR EVER POSSIBLE MOVES
    // for example
    // moveLeft if cant move to left store it in moveFlag
    // checkCost and store it in lCost
    // if moveFlag true then move back to right
    // repeat for every direction

    // rCost
    moveFlagR = moveEmptyCell(board, Input::right, MessageMode::none, false);
    rCost = checkIncorrects(board);
    if (moveFlagR)
        moveEmptyCell(board, Input::left, MessageMode::none, false);

    // lCost
    moveFlagL = moveEmptyCell(board, Input::left, MessageMode::none, false);
    lCost = checkIncorrects(board);
    if (moveFlagL)
        moveEmptyCell(board, Input::right, MessageMode::none, false);

    // uCost
    moveFlagU = moveEmptyCell(board, Input::up, MessageMode::none, false);
    uCost = checkIncorrects(board);
    if (moveFlagU)
        moveEmptyCell(board, Input::down, MessageMode::none, false);

    // dCost
    moveFlagD = moveEmptyCell(board, Input::down, MessageMode::none, false);
    dCost = checkIncorrects(board);
    if (moveFlagD)
        moveEmptyCell(board, Input::up, MessageMode::none, false);

    // ELIMINATE INVALID MOVES
    // if cant move then flag is false so ai should not pick it
    // also we dont want to repeat back to our move so store last move
    if (!moveFlagR || lastMove == Input::left)
        rCost = 999;
    if (!moveFlagL || lastMove == Input::right)
        lCost = 999;
    if (!moveFlagU || lastMove == Input::down)
        uCost = 999;
    if (!moveFlagD || lastMove == Input::up)
        dCost = 999;

    // Find the min cost
    minCost = min4(rCost, lCost, uCost, dCost);
    // std::cout << "rCost lCost uCost dCost minCost\n"
    //           << rCost << " " << lCost << " " << uCost << " " << dCost << " " << minCost << "\n";

    // Specify min values
    // There can exist multiple min values
    int countMins = 0;
    if (minCost == rCost)
    {
        minR = true;
        countMins++;
    }
    if (minCost == lCost)
    {
        minL = true;
        countMins++;
    }
    if (minCost == uCost)
    {
        minU = true;
        countMins++;
    }
    if (minCost == dCost)
    {
        minD = true;
        countMins++;
    }

    // If there exists only one minimum cost move there
    if (countMins == 1)
    {
        if (minR)
            return Input::right;
        if (minL)
            return Input::left;
        if (minU)
            return Input::up;
        if (minD)
            return Input::down;
    }

    // Pick randomly between min values
    // In some cases for example lCost can be equal to rCost
    // If i go rCost always it will go into a loop
    // So for these cases we pick randomly
    int select;
    do
    {
        select = randBetween(0, 3);
        switch (select)
        {
        case 0:
            if (minR)
            {
                return Input::right;
            }
            break;
        case 1:
            if (minL)
            {
                return Input::left;
            }
            break;
        case 2:
            if (minU)
            {
                return Input::up;
            }
            break;
        case 3:
            if (minD)
            {
                return Input::down;
            }
            break;

        default:
            break;
        }

    } while (true);

    return Input::invalid;
}

/**
 * Solve the board with stack solution and print moves
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard(Board *board)
{
    Input aiInput;
    int moves = 0;
    std::cout << "Ai is trying to solve board with stack solution...\n";
    while (checkIncorrects(board) > 0)
    {
        aiInput = aiMove(board);
        std::cout << "Ai choosed ";
        printInput(aiInput);
        std::cout << "\n";
        moveEmptyCell(board, aiInput, MessageMode::none, true);
        moves++;
    }
    return moves;
}

/**
 * Solve the board with branch and bound solution and print moves
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard2(Board *board)
{
    Input aiInput, lastMove;
    int moves = 0;
    std::cout << "Ai is trying to solve board with branch and bound...\n";
    while (checkIncorrects(board) > 0)
    {
        aiInput = aiMove2(board, lastMove);
        lastMove = aiInput;
        std::cout << "Ai choosed ";
        printInput(aiInput);
        std::cout << "\n";
        moveEmptyCell(board, aiInput, MessageMode::none, true);
        moves++;
        if(moves > 1000) {
            break;
        }
    }
    return moves;
}

/**
 * Checks the incorrect tiles on board.
 * 
 * @param *board [Board] pointer
 * @return [int] number of incorrect tiles
 */
int checkIncorrects(Board *board)
{
    int incorrects = 0;
    for (int i = 0; i < board->size; i++)
    {
        if (board->arr[i] != EMPTY && board->arr[i] != i + 1)
        {
            incorrects++;
        }
    }
    return incorrects;
}

/**
 * Print the given board giving 2 digit spaces to every cell.
 * 
 * @param *board [Board] pointer
 */
void printBoard(Board *board)
{
    for (int i = 0; i < board->size; i++)
    {
        // Print empty and non-empty tiles
        if (board->arr[i] != EMPTY)
        {
            std::cout << board->arr[i];
        }
        else
        {
            std::cout << "__";
        }

        // Check number of digits for alignment of board
        if (board->arr[i] / 10 <= 0 && board->arr[i] != EMPTY)
        {
            std::cout << "  ";
        }
        else
        {
            std::cout << " ";
        }

        // End of line
        if (i % board->dimension == board->dimension - 1)
        {
            std::cout << std::endl;
        }
    }
    std::cout << "\n";
}

/**
 * Initialize the given board with given dimensions.
 * Fill with solved end state.
 * 
 * @param *board [Board] pointer
 */
void initBoard(Board *board, int dimension)
{
    board->dimension = dimension;
    board->size = board->dimension * board->dimension;
    board->arr = (int *)malloc(sizeof(int) * board->size);
    //board->arr = new int[board->size];
    for (int i = 0; i < board->size; i++)
    {
        board->arr[i] = i + 1;
    }
    board->arr[board->size - 1] = EMPTY;
    board->emptyTile = board->size - 1;
    board->solution = NULL;
}