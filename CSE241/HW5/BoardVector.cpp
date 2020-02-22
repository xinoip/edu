#include "BoardVector.h"
#include <iostream>
#include <fstream>

namespace bugra
{
/**
 * Allocate and init 2D Array
*/
BoardVector::BoardVector()
{
    m_rowsize = 4;
    m_colsize = 4;
    arr.resize(m_rowsize);
    for (int i = 0; i < m_rowsize; i++)
    {
        arr[i].resize(m_colsize);
    }
    m_numberOfBoards++;
}

/**
 * Delete 2D Array
*/
BoardVector::~BoardVector()
{
}

/**
 * Loop through the 2D array
 * Print every cell content with alignment
*/
void BoardVector::print() const
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    int currentTile = 0;
    for (int i = 0; i < m_rowsize; i++)
    {
        for (int j = 0; j < m_colsize; j++)
        {
            currentTile = arr[i][j];
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

/**
 * Read the given file, get sizes
 * Return the beginning of the file
 * Read again and fill the newly sized board
*/
bool BoardVector::readFromFile(std::ifstream &file)
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    bool success = true;

    if (!file.is_open())
    {
        std::cerr << "File not found!!\n";
        success = false;
        return success;
    }

    // Go to begining of the file
    file.clear();
    file.seekg(0, std::ios::beg);

    char currChar;
    int currRow = 0, currCol = 0;
    int firstDigit, secondDigit, currNum;

    // Get size of the array
    unsigned int rowSize, colSize;
    while (file >> std::noskipws >> currChar)
    {
        switch (currChar)
        {
        case ' ':
            currCol++;
            break;
        case '\n':
            colSize = currCol + 1;
            currRow++;
            currCol = 0;
            break;
        case 'b':
            file >> std::noskipws >> currChar;
            break;

        default:
            file >> std::noskipws >> currChar;
            break;
        }
    }
    rowSize = currRow + 1;

    // Set new size and go back
    setSize(rowSize, colSize);
    file.clear();
    file.seekg(0, std::ios::beg);

    currRow = 0, currCol = 0;
    // Read and place contents of the array
    while (file >> std::noskipws >> currChar)
    {
        switch (currChar)
        {
        case ' ':
            currCol++;
            break;
        case '\n':
            currRow++;
            currCol = 0;
            break;
        case 'b':
            file >> std::noskipws >> currChar;
            arr[currRow][currCol] = EMPTY;
            break;

        default:
            firstDigit = currChar - '0';
            file >> std::noskipws >> currChar;
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

    return success;
}

/**
 * Write the contents to given file
*/
bool BoardVector::writeToFile(std::ofstream &file) const
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    bool success = true;

    if (!file.is_open())
    {
        std::cerr << "File not found!!\n";
        success = false;
        return success;
    }

    int currentTile = 0;
    for (int i = 0; i < m_rowsize; i++)
    {
        for (int j = 0; j < m_colsize; j++)
        {
            currentTile = arr[i][j];
            if (currentTile == EMPTY)
            {
                file << "bb";
            }
            else if (currentTile == BLOCK)
            {
                file << "00";
            }
            else
            {
                if (currentTile / 10 < 1)
                {
                    file << "0" << currentTile;
                }
                else
                {
                    file << currentTile;
                }
            }

            if (j != m_colsize - 1)
            {
                file << " ";
            }
        }
        if (i != m_rowsize - 1)
        {
            file << "\n";
        }
    }

    return success;
}

/**
 * Loop through the 2D array
 * Place every cell with correct data
*/
void BoardVector::reset()
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    int currCorrect = 1;
    for (int i = 0; i < m_rowsize; i++)
    {
        for (int j = 0; j < m_colsize; j++)
        {
            if ((*this)(i, j) != BLOCK)
            {
                arr[i][j] = currCorrect;
                currCorrect++;
            }
        }
    }
    arr[m_rowsize - 1][m_colsize - 1] = EMPTY;
    m_numberOfMoves = 0;
    m_lastMove = 'S';
}

/**
 * Delete old array
 * Set new sizes
 * Allocate new array with new sizes
 * Call reset()
*/
void BoardVector::setSize(unsigned int row, unsigned int col)
{
    // clear old vector
    arr.clear();
    for (int i = 0; i < m_rowsize; i++)
    {
        arr[i].clear();
    }

    // set new sizes
    m_rowsize = row;
    m_colsize = col;
    arr.resize(m_rowsize);
    for (int i = 0; i < m_rowsize; i++)
    {
        arr[i].resize(m_colsize);
    }

    // Reset to solution
    reset();
}

/**
 * Find empty space
 * Try to move it according to given param
 * Return true if moved
*/
bool BoardVector::move(char move)
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    bool isMoved = false;

    int emptyTileRow, emptyTileCol;
    bool foundEmpty = false;
    for (int i = 0; i < m_rowsize; i++)
    {
        for (int j = 0; j < m_colsize; j++)
        {
            if ((*this)(i, j) == EMPTY)
            {
                emptyTileRow = i;
                emptyTileCol = j;
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty)
            break;
    }

    if (!foundEmpty)
    {
        std::cout << "There are no empty tile to move!\n";
        return isMoved;
    }

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
        if ((*this)(newRow, newCol + 1) != BLOCK && emptyTileCol != m_colsize - 1)
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
        if ((*this)(newRow + 1, newCol) != BLOCK && emptyTileRow != m_rowsize - 1)
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
        int tmp = arr[emptyTileRow][emptyTileCol];
        arr[emptyTileRow][emptyTileCol] = arr[newRow][newCol];
        arr[newRow][newCol] = tmp;
        emptyTileRow = newRow;
        emptyTileCol = newCol;
        m_numberOfMoves++;
        m_lastMove = move;
    }

    return isMoved;
}

/**
 * Safe access to 2D array
*/
int BoardVector::operator()(unsigned int row, unsigned int col) const
{
    const int BLOCK = -2;
    if (row < m_rowsize && col < m_colsize && row >= 0 && col >= 0)
    {
        return arr[row][col];
    }
    else
    {
        return BLOCK;
    }
}
} // namespace bugra