#include "BoardVector.h"
#include "BoardArray1D.h"
#include "BoardArray2D.h"
#include "Drivers.h"
#include "GlobalFunction.h"

int main()
{
    bugra::BoardArray1D boardArray1D;
    bugra::test::testBoard(boardArray1D);

    bugra::BoardArray2D boardArray2D;
    bugra::test::testBoard(boardArray2D);

    bugra::BoardVector boardVector;
    bugra::test::testBoard(boardVector);

    bugra::AbstractBoard *boards[5];
    boards[0] = new bugra::BoardArray1D();
    boards[1] = new bugra::BoardArray1D();
    boards[2] = new bugra::BoardArray2D();
    boards[3] = new bugra::BoardArray2D();
    boards[4] = new bugra::BoardVector();
    

    for (int i = 0; i < 5; i++)
    {
        boards[i]->setSize(5, 5);
    }
    std::cout << "Board 0: \n";
    boards[0]->print();

    boards[1]->move('L');
    std::cout << "Board 1: \n";
    boards[1]->print();

    boards[2]->move('L');
    boards[2]->move('U');
    std::cout << "Board 2: \n";
    boards[2]->print();
    std::cout << "\n";

    boards[3]->move('L');
    boards[3]->move('U');
    boards[3]->move('R');
    std::cout << "Board 3: \n";
    boards[3]->print();
    std::cout << "\n";

    boards[4]->move('L');
    boards[4]->move('U');
    boards[4]->move('R');
    boards[4]->move('U');
    std::cout << "Board 4: \n";
    boards[4]->print();
    

    if (isValidSequence(boards, 5))
    {
        std::cout << "\n\nValid sequence!\n";
    }
    else
    {
        std::cout << "\n\nNot Valid sequence!\n";
    }

    std::cout << "Demo done!\nBugra Eren Yilmaz\n1801042669\n\n";
}
