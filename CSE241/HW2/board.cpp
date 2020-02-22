#include "./board.h"

/**
 * Initialize the given board with data from given file.
 * Fill with data from given file.
 * 
 * @param *board [Board] pointer
 * @param *fileName [String] file to load
 */
bool loadBoard(Board *board, const char *fileName)
{
    std::cout << "Loading board from " << fileName << std::endl;
    bool success = true;
    std::ifstream boardFile;
    boardFile.open(fileName);

    if (!boardFile.is_open())
    {
        std::cerr << "File not found!!\n";
        success = false;
        return success;
    }

    // Read the file char by char
    // do not skip white spaces
    char currChar;
    // currRow and currCol, positions for 2D array
    int currRow = 0, currCol = 0;
    // get first digit, multiply it by 10
    // sum the result with second digit
    // currNum is result of sum
    int firstDigit, secondDigit, currNum;
    while (boardFile >> std::noskipws >> currChar)
    {
        switch (currChar)
        {
        case ' ':
            currCol++;
            break;
        case '\n':
            board->width = currCol + 1;
            currRow++;
            currCol = 0;
            break;
        case 'b':
            boardFile >> std::noskipws >> currChar;
            board->arr[currRow][currCol] = EMPTY;
            board->emptyTileRow = currRow;
            board->emptyTileCol = currCol;
            break;

        default:
            // get the first digit by converting char to int
            firstDigit = currChar - '0';
            // read and get the second digit by converting char to int
            boardFile >> std::noskipws >> currChar;
            secondDigit = currChar - '0';
            // basic digit arithmetic
            currNum = firstDigit * 10 + secondDigit;

            if (currNum == 0)
            {
                board->arr[currRow][currCol] = BLOCK;
            }
            else
            {
                board->arr[currRow][currCol] = currNum;
            }
            break;
        }
    }
    board->height = currRow + 1;
    board->moves = 0;

    boardFile.close();
    return success;
}

/**
 * Save the current board to given fileName.
 * 
 * @param *board [Board] pointer
 * @param *fileName [String] file to save
 */
void saveBoard(Board *board, const char *fileName)
{
    std::cout << "Saving board to " << fileName << std::endl;
    std::ofstream boardFile;
    boardFile.open(fileName);

    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            switch (board->arr[i][j])
            {
            case EMPTY:
                boardFile << "bb";
                break;
            case BLOCK:
                boardFile << "00";
                break;

            default:
                if (board->arr[i][j] / 10 < 1)
                {
                    boardFile << "0" << board->arr[i][j];
                }
                else
                {
                    boardFile << board->arr[i][j];
                }
                break;
            }
            if (j != board->width - 1)
            {
                boardFile << " ";
            }
        }
        if (i != board->height - 1)
        {
            boardFile << "\n";
        }
    }
    boardFile.close();
}

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
            isMoved = moveEmptyCell(board, Input::up, MessageMode::none);
            break;
        case 1:
            isMoved = moveEmptyCell(board, Input::down, MessageMode::none);
            break;
        case 2:
            isMoved = moveEmptyCell(board, Input::left, MessageMode::none);
            break;
        case 3:
            isMoved = moveEmptyCell(board, Input::right, MessageMode::none);
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
bool moveEmptyCell(Board *board, Input input, MessageMode messageMode)
{
    bool isMoved = false;
    int newRow = board->emptyTileRow, newCol = board->emptyTileCol;
    switch (input)
    {
    case Input::left:
        if (board->arr[newRow][newCol - 1] != BLOCK && board->emptyTileCol != 0)
        {
            printMessageMode(messageMode, "moved left");
            newCol--;
            isMoved = true;
        }
        break;
    case Input::right:
        if (board->arr[newRow][newCol + 1] != BLOCK && board->emptyTileCol != board->width - 1)
        {
            printMessageMode(messageMode, "moved right");
            newCol++;
            isMoved = true;
        }
        break;

    case Input::up:
        if (board->arr[newRow - 1][newCol] != BLOCK && board->emptyTileRow != 0)
        {
            printMessageMode(messageMode, "moved up");
            newRow--;
            isMoved = true;
        }
        break;

    case Input::down:
        if (board->arr[newRow + 1][newCol] != BLOCK && board->emptyTileRow != board->height - 1)
        {
            printMessageMode(messageMode, "moved down");
            newRow++;
            isMoved = true;
        }
        break;
    default:
        break;
    }
    if (isMoved)
    {
        swap(&board->arr[board->emptyTileRow][board->emptyTileCol], &board->arr[newRow][newCol]);
        board->emptyTileRow = newRow;
        board->emptyTileCol = newCol;
    }

    return isMoved;
}

Input aiMove(Board *board, Input lastMove)
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
    moveFlagR = moveEmptyCell(board, Input::right, MessageMode::none);
    rCost = checkIncorrects(board);
    if (moveFlagR)
        moveEmptyCell(board, Input::left, MessageMode::none);

    // lCost
    moveFlagL = moveEmptyCell(board, Input::left, MessageMode::none);
    lCost = checkIncorrects(board);
    if (moveFlagL)
        moveEmptyCell(board, Input::right, MessageMode::none);

    // uCost
    moveFlagU = moveEmptyCell(board, Input::up, MessageMode::none);
    uCost = checkIncorrects(board);
    if (moveFlagU)
        moveEmptyCell(board, Input::down, MessageMode::none);

    // dCost
    moveFlagD = moveEmptyCell(board, Input::down, MessageMode::none);
    dCost = checkIncorrects(board);
    if (moveFlagD)
        moveEmptyCell(board, Input::up, MessageMode::none);

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
 * Solve the board with branch and bound solution and print moves
 * 
 * @param *board [Board] pointer
 * @return [int] number of moves
 */
int solveBoard(Board *board)
{
    Input aiInput, lastMove;
    int moves = 0;
    std::cout << "Ai is trying to solve board with branch and bound...\n";
    while (checkIncorrects(board) > 0)
    {
        aiInput = aiMove(board, lastMove);
        lastMove = aiInput;
        std::cout << "Ai choosed ";
        printInput(aiInput);
        std::cout << "\n";
        moveEmptyCell(board, aiInput, MessageMode::none);
        board->moves++;
        moves++;

        // throw some random moves, if stuck
        if(moves % 5000 == 0) {
            mixBoard(board, 10);
        }

        if (moves > AI_LIMIT)
        {
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
    int currCorrect = 1;
    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            if (board->arr[i][j] != BLOCK)
            {
                if (board->arr[i][j] != EMPTY && board->arr[i][j] != currCorrect)
                {
                    incorrects++;
                }
                currCorrect++;
            }
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
    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            switch (board->arr[i][j])
            {
            case EMPTY:
                std::cout << "__";
                break;
            case BLOCK:
                std::cout << "WW";
                break;
            default:
                std::cout << board->arr[i][j];
                break;
            }

            // Check number of digits for alignment of board
            if (board->arr[i][j] / 10 <= 0 && board->arr[i][j] != EMPTY && board->arr[i][j] != BLOCK)
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

/**
 * Initialize the given board with given dimensions.
 * Fill with solved end state.
 * 
 * @param *board [Board] pointer
 */
void initBoard(Board *board, int dimension)
{
    int currNum = 1;
    board->width = dimension;
    board->height = dimension;
    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            board->arr[i][j] = currNum;
            currNum++;
        }
    }

    board->arr[board->height - 1][board->width - 1] = EMPTY;
    board->emptyTileCol = board->width - 1;
    board->emptyTileRow = board->height - 1;
    board->moves = 0;
}