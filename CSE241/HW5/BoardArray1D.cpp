#include "BoardArray1D.h"

#include <iostream>

namespace bugra
{
BoardArray1D::BoardArray1D()
{
    m_rowsize = 4;
    m_colsize = 4;
    arr = new int[m_rowsize * m_colsize];
    m_numberOfBoards++;
    reset();
}

BoardArray1D::~BoardArray1D()
{
    delete[] arr;
}

void BoardArray1D::print() const
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    int size = m_rowsize * m_colsize;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == BLOCK)
        {
            std::cout << "WW";
        }
        else if (arr[i] == EMPTY)
        {
            std::cout << "__";
        }
        else
        {
            std::cout << arr[i];
        }

        // Check number of digits for alignment of board
        if (arr[i] / 10 <= 0 && arr[i] != EMPTY && arr[i] != BLOCK)
        {
            std::cout << "  ";
        }
        else
        {
            std::cout << " ";
        }

        // End of line
        if (i % m_colsize == m_colsize - 1)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

bool BoardArray1D::readFromFile(std::ifstream &file)
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
            arr[(currRow * m_colsize) + currCol] = EMPTY;
            break;

        default:
            firstDigit = currChar - '0';
            file >> std::noskipws >> currChar;
            secondDigit = currChar - '0';
            currNum = firstDigit * 10 + secondDigit;

            if (currNum == 0)
            {
                arr[(currRow * m_colsize) + currCol] = BLOCK;
            }
            else
            {
                arr[(currRow * m_colsize) + currCol] = currNum;
            }
            break;
        }
    }

    return success;
}

bool BoardArray1D::writeToFile(std::ofstream &file) const
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
    for (int i = 0; i < m_rowsize * m_colsize; i++)
    {
        currentTile = arr[i];
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

        if (i % m_colsize != m_colsize - 1)
        {
            file << " ";
        }

        if (i < (m_rowsize - 1) * m_colsize && i % m_colsize == m_colsize - 1)
        {
            file << "\n";
        }
    }

    return success;
}

void BoardArray1D::reset()
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    int currCorrect = 1;
    int size = m_rowsize * m_colsize;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != BLOCK)
        {
            arr[i] = currCorrect;
            currCorrect++;
        }
    }
    arr[size - 1] = EMPTY;
    m_numberOfMoves = 0;
    m_lastMove = 'S';
}

void BoardArray1D::setSize(unsigned int row, unsigned int col)
{
    // Delete old array
    for (int i = 0; i < m_rowsize * m_colsize; i++)
    {
        arr[i] = i + 1;
    }
    delete[] arr;

    // Set new sizes
    m_rowsize = row;
    m_colsize = col;

    // Alloc new array
    arr = new int[m_rowsize * m_colsize];

    // Reset to solution
    reset();
}

bool BoardArray1D::move(char move)
{
    const int EMPTY = -1;
    const int BLOCK = -2;
    bool isMoved = false;

    int emptyTileRow, emptyTileCol;

    // Find the empty tile
    int emptyTileIndex;
    int size = m_rowsize * m_colsize;
    bool foundEmpty = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == EMPTY)
        {
            emptyTileIndex = i;
            foundEmpty = true;
            break;
        }

        if (foundEmpty)
            break;
    }

    if (!foundEmpty)
    {
        std::cout << "There are no empty tile to move!\n";
        return isMoved;
    }

    emptyTileRow = emptyTileIndex / m_colsize;
    emptyTileCol = emptyTileIndex % m_colsize;

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
        int newIndex = (newRow * m_colsize) + newCol;
        int tmp = arr[emptyTileIndex];
        arr[emptyTileIndex] = arr[newIndex];
        arr[newIndex] = tmp;
        emptyTileRow = newRow;
        emptyTileCol = newCol;
        m_numberOfMoves++;
        m_lastMove = move;
    }

    return isMoved;
}

int BoardArray1D::operator()(unsigned int row, unsigned int col) const
{
    const int BLOCK = -2;
    if (row < m_rowsize && col < m_colsize && row >= 0 && col >= 0)
    {
        return arr[(row * m_colsize) + col];
    }
    else
    {
        return BLOCK;
    }
}
} // namespace bugra