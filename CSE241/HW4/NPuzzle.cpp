#include "NPuzzle.h"

NPuzzle::NPuzzle()
{
    boards.push_back(Board());
}

std::istream &operator>>(std::istream &is, NPuzzle &puzzle)
{
    // ifstream is an istream by polymorphism and inheritence
    // so i used static casting to make an `upcast` from ifstream to istream
    // then passed the new ifstream to my previously written readFile function
    std::ifstream &file = static_cast<std::ifstream &>(is);
    puzzle.readFromFile(file);
    return is;
}

std::ostream &operator<<(std::ostream &os, const NPuzzle &puzzle)
{
    // just used the previously written function
    puzzle.print();
    return os;
}

void NPuzzle::print() const
{
    boards[0].print();
}

void NPuzzle::printReport() const
{
    std::cout << boards[0].getNumberOfMoves() << " moves done and";
    if (boards[0].isSolved())
    {
        std::cout << " solution found!\n";
    }
    else
    {
        std::cout << " solution not found!\n";
    }
}

bool NPuzzle::readFromFile(std::ifstream &boardFile)
{
    bool success = false;
    boards[0].setNumberOfMoves(0);
    success = boards[0].readFromFile(boardFile);
    numberOfShuffles = boards[0].getWidth() * boards[0].getHeight();
    return success;
}

void NPuzzle::writeToFile(const char *fileName) const
{
    boards[0].writeToFile(fileName);
}

void NPuzzle::shuffle()
{
    reset();
    int i = 0;
    while (i < numberOfShuffles)
    {
        moveRandom();
        i++;
    }
    boards[0].setNumberOfMoves(0);
}

void NPuzzle::reset()
{
    boards[0].setNumberOfMoves(0);
    boards[0].reset();
}

void NPuzzle::setSize(int width, int height)
{
    boards[0].setSize(width, height);
    boards[0].reset();
    numberOfShuffles = width * height;
}

char NPuzzle::moveRandom()
{
    int random = 0;
    char randomMove = 0;
    do
    {
        random = BasicUtils::randBetween(0, 3);
        switch (random)
        {
        case 0:
            randomMove = 'U';
            break;
        case 1:
            randomMove = 'D';
            break;
        case 2:
            randomMove = 'L';
            break;
        case 3:
            randomMove = 'R';
            break;

        default:
            break;
        }
    } while (!move(randomMove));
    return randomMove;
    boards[0].setNumberOfMoves(boards[0].getNumberOfMoves() + 1);
}

bool NPuzzle::move(char move)
{
    bool success = boards[0].move(move);
    if (success)
        boards[0].setNumberOfMoves(boards[0].getNumberOfMoves() + 1);
    return success;
}

bool NPuzzle::solvePuzzle()
{
    bool solutionFound = false;
    if (boards[0].isSolved())
    {
        std::cout << "It is already solved!\n";
        return true;
    }

    int i = 0;
    int nom = 1;
    while (!solutionFound)
    {
        // take board at index i
        Board currBoard = boards[i++];
        char lastMove = currBoard.getLastMove();
        for (int j = 0; j < 4; j++)
        {
            // make copy of the current board
            Board tmp = currBoard;
            bool isMoved = false;
            switch (j)
            {
            case 0:
                //try to move right
                if (lastMove != 'L')
                {
                    isMoved = tmp.move('R');
                    if (isMoved)
                    {
                        tmp.setLastMove('R');
                        tmp.setNumberOfMoves(nom);
                    }
                }
                break;
            case 1:
                //L
                if (lastMove != 'R')
                {
                    isMoved = tmp.move('L');
                    if (isMoved)
                    {
                        tmp.setLastMove('L');
                        tmp.setNumberOfMoves(nom);
                    }
                }
                break;
            case 2:
                //U
                if (lastMove != 'D')
                {
                    isMoved = tmp.move('U');
                    if (isMoved)
                    {
                        tmp.setLastMove('U');
                        tmp.setNumberOfMoves(nom);
                    }
                }
                break;
            case 3:
                //D
                if (lastMove != 'U')
                {
                    isMoved = tmp.move('D');
                    if (isMoved)
                    {
                        tmp.setLastMove('D');
                        tmp.setNumberOfMoves(nom);
                    }
                }
                break;
            default:
                break;
            }

            // check if moved
            if (isMoved)
            {
                // check if the new board is not a duplicate
                bool isDuplicate = false;
                for (unsigned k = 0; k < boards.size(); k++)
                {
                    if (boards[k] == tmp)
                    {
                        isDuplicate = true;
                        break;
                    }
                }

                // if it is not a duplicate, push to vector
                if (!isDuplicate)
                {
                    boards.push_back(tmp);
                    if (tmp.isSolved())
                    {
                        // win condition
                        std::cout << "Found the solution!\n";
                        tmp.print();
                        printSolution();
                        std::cout << "\n";
                        boards.resize(0);
                        boards.push_back(tmp);
                        solutionFound = true;
                        return true;
                    }
                }
            }
        }

        nom++;
    }

    return solutionFound;
}

void NPuzzle::printSolution()
{
    std::vector<char> solution;

    // start from the last board   
    char currMove = boards[boards.size() - 1].getLastMove();
    char inverseMove = BasicUtils::inverseMove(currMove);
    solution.push_back(currMove);
 
    // make copy of it
    Board targetBoard = boards[boards.size() - 1];

    // to find previous state of the board move the copy of it
    targetBoard.move(inverseMove);

    for (int i = boards.size() - 1; i > 0; i--)
    {
        // try to find previous state of the board
        if (boards[i] == targetBoard)
        {
            // push the moves
            currMove = boards[i].getLastMove();
            inverseMove = BasicUtils::inverseMove(currMove);
            solution.push_back(currMove);

            // to find next previous state of the board move the copy of it
            targetBoard.move(inverseMove);
        }
    }

    // print the solution vector backwards
    std::cout << "solutionSize: " << solution.size() << "\n";
    for (int j = solution.size() - 1; j >= 0; j--)
    {
        std::cout << solution[j] << "\n";
    }
}
