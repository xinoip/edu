#ifndef _Board_Array_2D_h_
#define _Board_Array_2D_h_

#include "AbstractBoard.h"

namespace bugra
{
class BoardArray2D : public AbstractBoard
{
private:
    int **arr;

public:
    BoardArray2D();
    ~BoardArray2D() override;
    void print() const override;
    bool readFromFile(std::ifstream &file) override;
    bool writeToFile(std::ofstream &file) const override;
    void reset() override;
    void setSize(unsigned int row, unsigned int col) override;
    bool move(char move) override;
    int operator()(unsigned int row, unsigned int col) const override;
};
} // namespace bugra

#endif