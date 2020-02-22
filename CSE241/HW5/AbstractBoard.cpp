#include "AbstractBoard.h"

namespace bugra
{
unsigned int AbstractBoard::m_numberOfBoards = 0;

unsigned int AbstractBoard::NumberOfBoards() const
{
    return m_numberOfBoards;
}

char AbstractBoard::lastMove() const
{
    return m_lastMove;
}

void AbstractBoard::getSize(unsigned int &rowsize, unsigned int &colsize) const
{
    rowsize = m_rowsize;
    colsize = m_colsize;
}

unsigned int AbstractBoard::numberOfMoves() const
{
    return m_numberOfMoves;
}

bool AbstractBoard::operator==(const AbstractBoard &board) const
{
    unsigned int otherRowSize, otherColSize;
    board.getSize(otherRowSize, otherColSize);
    if (otherColSize == m_colsize && otherRowSize == m_rowsize)
    {
        for (int i = 0; i < m_rowsize; i++)
        {
            for (int j = 0; j < m_colsize; j++)
            {
                if (board(i, j) != (*this)(i, j))
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

    return true;
}

bool AbstractBoard::isSolved() const
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
} // namespace bugra