#include "NPuzzle.h"

NPuzzle::Board::Board()
{
    width = 9;
    height = 9;
    reset();
}

void NPuzzle::Board::print() const
{
    int currentTile = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            currentTile = arr[i][j];
            if(currentTile == EMPTY) {
                std::cout << "__";
                
            } else if(currentTile == BLOCK) {
                std::cout << "WW";
                
            } else {
                std::cout << currentTile;

            }

            // Check number of digits for alignment of board
            if (currentTile / 10 <= 0 && currentTile != EMPTY && currentTile != BLOCK)
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

bool NPuzzle::Board::readFromFile(const char *fileName)
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

    char currChar;
    int currRow = 0, currCol = 0;
    int firstDigit, secondDigit, currNum;
    while (boardFile >> std::noskipws >> currChar)
    {
        switch (currChar)
        {
        case ' ':
            currCol++;
            break;
        case '\n':
            width = currCol + 1;
            currRow++;
            currCol = 0;
            break;
        case 'b':
            boardFile >> std::noskipws >> currChar;
            arr[currRow][currCol] = EMPTY;
            emptyTileRow = currRow;
            emptyTileCol = currCol;
            break;

        default:
            firstDigit = currChar - '0';
            boardFile >> std::noskipws >> currChar;
            secondDigit = currChar - '0';
            currNum = firstDigit * 10 + secondDigit;

            if (currNum == 0)
            {
                arr[currRow][currCol] = BLOCK;
            }
            else
            {
                arr[currRow][currCol] = currNum;
            }
            break;
        }
    }
    height = currRow + 1;

    boardFile.close();
    return success;
    //std::cout << board->width << "x" << board->height << "\n";
}

void NPuzzle::Board::writeToFile(const char *fileName) const
{
    std::cout << "Saving board to " << fileName << std::endl;
    std::ofstream boardFile;
    boardFile.open(fileName);

    int currentTile = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            currentTile = arr[i][j];
            if(currentTile == EMPTY) {
                boardFile << "bb";
                
            } else if(currentTile == BLOCK) {
                boardFile << "00";
                
            } else {
                if (currentTile / 10 < 1)
                {
                    boardFile << "0" << currentTile;
                }
                else
                {
                    boardFile << currentTile;
                }

            }

            if (j != width - 1)
            {
                boardFile << " ";
            }
        }
        if (i != height - 1)
        {
            boardFile << "\n";
        }
    }
    boardFile.close();
}

void NPuzzle::Board::reset()
{
    int currCorrect = 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arr[i][j] != BLOCK)
            {
                arr[i][j] = currCorrect;
                currCorrect++;
            }
        }
    }
    emptyTileRow = height - 1;
    emptyTileCol = width - 1;
    arr[emptyTileRow][emptyTileCol] = EMPTY;
}

void NPuzzle::Board::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
    reset();
}

bool NPuzzle::Board::move(char move)
{
    bool isMoved = false;
    int newRow = emptyTileRow, newCol = emptyTileCol;
    switch (move)
    {
    case 'L':
        if (arr[newRow][newCol - 1] != BLOCK && emptyTileCol != 0)
        {

            newCol--;
            isMoved = true;
        }
        break;
    case 'R':
        if (arr[newRow][newCol + 1] != BLOCK && emptyTileCol != width - 1)
        {

            newCol++;
            isMoved = true;
        }
        break;

    case 'U':
        if (arr[newRow - 1][newCol] != BLOCK && emptyTileRow != 0)
        {

            newRow--;
            isMoved = true;
        }
        break;

    case 'D':
        if (arr[newRow + 1][newCol] != BLOCK && emptyTileRow != height - 1)
        {

            newRow++;
            isMoved = true;
        }
        break;
    default:
        break;
    }
    if (isMoved)
    {
        BasicUtils::swap(&arr[emptyTileRow][emptyTileCol], &arr[newRow][newCol]);
        emptyTileRow = newRow;
        emptyTileCol = newCol;
    }

    return isMoved;
}

bool NPuzzle::Board::isSolved() const
{
    int currCorrect = 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arr[i][j] != BLOCK)
            {
                if (arr[i][j] != EMPTY && arr[i][j] != currCorrect)
                {
                    return false;
                }
                currCorrect++;
            }
        }
    }
    return true;
}

void NPuzzle::Board::findExpectedPlace(int value, int *row, int *col) const
{
    int currCorrectNum = 1;
    int currNum = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            currNum = arr[i][j];
            if (currNum != BLOCK)
            {
                if (currCorrectNum == value)
                {
                    *row = i;
                    *col = j;
                    return;
                }
                currCorrectNum++;
            }
        }
    }
}

int NPuzzle::Board::findManhattan(int row, int col) const
{
    int currNum = arr[row][col];
    int expectedRow, expectedCol, diffRow, diffCol;
    findExpectedPlace(currNum, &expectedRow, &expectedCol);
    diffRow = abs(row - expectedRow);
    diffCol = abs(col - expectedCol);
    return diffRow + diffCol;
}

void NPuzzle::Board::findCosts(int *up, int *down, int *left, int *right) const
{
    int currRow = emptyTileRow, currCol = emptyTileCol;

    // check up
    currRow = emptyTileRow - 1;
    currCol = emptyTileCol;
    if(currRow >= 0 && arr[currRow][currCol] != BLOCK) {
        *up = findManhattan(currRow, currCol);

    } else {
        *up = 0;

    }

    // check down
    currRow = emptyTileRow + 1;
    currCol = emptyTileCol;
    if(currRow < height && arr[currRow][currCol] != BLOCK) {
        *down = findManhattan(currRow, currCol);

    } else {
        *down = 0;

    }
    
    // check left
    currRow = emptyTileRow;
    currCol = emptyTileCol - 1;
    if(currCol >= 0 && arr[currRow][currCol] != BLOCK) {
        *left = findManhattan(currRow, currCol);

    } else {
        *left = 0;

    }

    // check right
    currRow = emptyTileRow;
    currCol = emptyTileCol + 1;
    if(currCol < width && arr[currRow][currCol] != BLOCK) {
        *right = findManhattan(currRow, currCol);

    } else {
        *right = 0;

    }
}