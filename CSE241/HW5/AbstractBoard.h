#ifndef _Abstract_Board_h_
#define _Abstract_Board_h_

#include <fstream>

namespace bugra
{
class AbstractBoard
{
protected:
    static unsigned int m_numberOfBoards;
    char m_lastMove;
    unsigned int m_numberOfMoves;
    unsigned int m_rowsize, m_colsize;

public:
    virtual ~AbstractBoard(){};
    virtual void print() const = 0;
    virtual bool readFromFile(std::ifstream &file) = 0;
    virtual bool writeToFile(std::ofstream &file) const  = 0;
    virtual void reset() = 0;
    virtual void setSize(unsigned int row, unsigned int col) = 0;
    virtual bool move(char move) = 0;
    virtual bool isSolved() const;
    virtual int operator()(unsigned int row, unsigned int col) const  = 0;
    virtual bool operator==(const AbstractBoard &board) const;
    virtual unsigned int NumberOfBoards() const;
    virtual char lastMove() const;
    virtual void getSize(unsigned int &rowsize, unsigned int &colsize) const;
    virtual unsigned int numberOfMoves() const;
};
} // namespace bugra

#endif