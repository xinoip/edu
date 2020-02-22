#include "AbstractBoard.h"
#include <iostream>

namespace bugra
{
namespace test
{

void testBoard(AbstractBoard &board)
{
    std::ifstream ifile;
    std::ofstream ofile;
    ofile.open("testOut.txt");
    ifile.open("testRead.txt");

    std::cout << "\n\n\nBasic setSize and printing: \n";
    board.setSize(4, 4);
    board.print();

    std::cout << "Dynamic alloc demo, big board: \n";
    board.setSize(24, 22);
    board.print();

    std::cout << "Writing to file...\n";
    board.writeToFile(ofile);
    std::cout << "Write to file done: testOut.txt\n\n";

    std::cout << "Reading from file...\n";
    board.readFromFile(ifile);
    std::cout << "Read file done: testRead.txt, printing: \n";
    board.print();

    std::cout << "\nReseting board that has walls in it: \n";
    board.reset();
    std::cout << "Reset done, printing: \n";
    board.print();

    // after reset it should be solved
    std::cout << "Testing isSolved: \n";
    if (board.isSolved())
    {
        std::cout << "isSolved test passed! \n";
    }
    else
    {
        std::cout << "isSolved test failed! \n";
    }

    std::cout << "Testing getters: \n";
    std::cout << "NumberOfBoards: " << board.NumberOfBoards() << "\n";
    std::cout << "lastMove: " << board.lastMove() << "\n";
    std::cout << "numberOfMoves: " << board.numberOfMoves() << "\n";

    std::cout << "\nTest done, check files and results!\n";
    std::cout << "Press any key to continue to next test...";
    ofile.close();
    ifile.close();
    std::cin.get();
}

} // namespace test
} // namespace bugra