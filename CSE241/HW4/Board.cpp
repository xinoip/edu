#include "NPuzzle.h"

int NPuzzle::Board::getWidth() const { return width; }
int NPuzzle::Board::getHeight() const { return height; }
int NPuzzle::Board::getEmptyTileRow() const { return emptyTileRow; }
int NPuzzle::Board::getEmptyTileCol() const { return emptyTileCol; }
int NPuzzle::Board::getNumberOfMoves() const { return numberOfMoves; }
void NPuzzle::Board::setNumberOfMoves(int value) { numberOfMoves = value; }
char NPuzzle::Board::getLastMove() const { return lastMove; }
void NPuzzle::Board::setLastMove(char value) { lastMove = value; }

// basic assignment operator for copying boards
void NPuzzle::Board::operator=(Board &board) const
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board.arr[i][j] = arr[i][j];
        }
    }
    board.width = width;
    board.height = height;
    board.emptyTileCol = emptyTileCol;
    board.emptyTileRow = emptyTileRow;
    board.lastMove = lastMove;
    board.numberOfMoves = numberOfMoves;
}

int NPuzzle::Board::operator()(int row, int col) const
{
    if (row < width && col < height && row >= 0 && col >= 0)
    {
        return arr[row][col];
    }
    else
    {
        return BLOCK;
    }
}

bool NPuzzle::Board::operator==(const Board &board) const
{
    if (board.getWidth() == width && board.getHeight() == height)
    {
        if (board.getEmptyTileRow() == emptyTileRow && board.getEmptyTileCol() == emptyTileCol)
        {
            for (int row = 0; row < height; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    if (board(row, col) != (*this)(row, col))
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

int NPuzzle::Board::NumberOfBoards() {
    return noBoards;
}

int NPuzzle::Board::noBoards = 0;

NPuzzle::Board::Board()
{
    width = 9;
    height = 9;
    arr.resize(width);
    for (int i = 0; i < height; i++)
    {
        arr[i].resize(height);
    }

    this->noBoards++;

    reset();
}

void NPuzzle::Board::print() const
{
    int currentTile = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            currentTile = (*this)(i, j);
            if (currentTile == EMPTY)
            {
                std::cout << "__";
            }
            else if (currentTile == BLOCK)
            {
                std::cout << "WW";
            }
            else
            {
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

bool NPuzzle::Board::readFromFile(std::ifstream& boardFile)
{
    // std::cout << "Loading board from " << fileName << std::endl;
    bool success = true;
    // std::ifstream boardFile;
    // boardFile.open(fileName);

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
            currentTile = (*this)(i, j);
            if (currentTile == EMPTY)
            {
                boardFile << "bb";
            }
            else if (currentTile == BLOCK)
            {
                boardFile << "00";
            }
            else
            {
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
            if ((*this)(i, j) != BLOCK)
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
        if ((*this)(newRow, newCol - 1) != BLOCK && emptyTileCol != 0)
        {

            newCol--;
            isMoved = true;
        }
        break;
    case 'R':
        if ((*this)(newRow, newCol + 1) != BLOCK && emptyTileCol != width - 1)
        {

            newCol++;
            isMoved = true;
        }
        break;

    case 'U':
        if ((*this)(newRow - 1, newCol) != BLOCK && emptyTileRow != 0)
        {

            newRow--;
            isMoved = true;
        }
        break;

    case 'D':
        if ((*this)(newRow + 1, newCol) != BLOCK && emptyTileRow != height - 1)
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
            if ((*this)(i, j) != BLOCK)
            {
                if ((*this)(i, j) != EMPTY && (*this)(i, j) != currCorrect)
                {
                    return false;
                }
                currCorrect++;
            }
        }
    }
    return true;
}