#ifndef _Board_Vector_h_
#define _Board_Vector_h_

#include "AbstractBoard.h"
#include <vector>

namespace bugra
{
class BoardVector : public AbstractBoard
{
private:
    std::vector<std::vector<int>> arr;

public:
    BoardVector();
    ~BoardVector() override;
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