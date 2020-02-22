#include "NPuzzle.h"

void NPuzzle::print() const
{
    board.print();
}

void NPuzzle::printReport() const
{
    std::cout << numberOfMoves << " moves done and";
    if (board.isSolved())
    {
        std::cout << " solution found!\n";
    }
    else
    {
        std::cout << " solution not found!\n";
    }
}

bool NPuzzle::readFromFile(const char *fileName)
{
    numberOfMoves = 0;
    return board.readFromFile(fileName);
}

void NPuzzle::writeToFile(const char *fileName) const
{
    board.writeToFile(fileName);
}

void NPuzzle::shuffle(int n)
{
    int i = 0;
    while (i < n)
    {
        moveRandom();
        i++;
    }
    numberOfMoves = 0;
}

void NPuzzle::reset()
{
    numberOfMoves = 0;
    board.reset();
}

void NPuzzle::setSize(int width, int height)
{
    board.setSize(width, height);
    board.reset();
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
    numberOfMoves++;
}

/**
 * A* search with heurstic of manhattan distance changes
 * Check all directions, up, down, left, right
 * Store manhattan costs in initUp, initDown, initLeft, initRight
 * 
 * Then try to move every direction
 * Store new manhattan costs in movedUp, movedDown, movedLeft, movedRight
 * If move is invalid store -2 as the cost and set the flags to false.
 * 
 * Calculate difference between old manhattan cost and the new one.
 * Store them in sumUp, sumDown, sumLeft, sumRight
 * 
 * Find the maximum of sums.
 * If there exists only 1 maximum, move there.
 * If there exists multiple maximums, choose randomly between maximums.
 * 
 * If all of them is negative, board is stuck, move randomly 5 times.
 */
void NPuzzle::moveIntelligent()
{
    if (board.isSolved())
    {
        std::cout << "Board is already solved!\n";
        return;
    }

    std::cout << "AI choosed ";

    // initial costs
    int initUp, initDown, initLeft, initRight;
    board.findCosts(&initUp, &initDown, &initLeft, &initRight);

    // is it maximum?
    bool maxUp = false, maxDown = false, maxLeft = false, maxRight = false;
    // can it move there?
    bool upFlag = true, downFlag = true, leftFlag = true, rightFlag = true;
    // cost after moving there
    int movedUp, movedDown, movedLeft, movedRight;
    // cost difference after moving there
    int sumUp, sumDown, sumLeft, sumRight;

    // check up
    if (move('U'))
    {
        board.findCosts(&movedUp, &movedDown, &movedLeft, &movedRight);
        sumUp = (initUp - movedDown);
        move('D');
        numberOfMoves-=2;
    }
    else
    {
        sumUp = -2;
        upFlag = false;
    }

    // check down
    if (move('D'))
    {
        board.findCosts(&movedUp, &movedDown, &movedLeft, &movedRight);
        sumDown = (initDown - movedUp);
        move('U');
        numberOfMoves-=2;
    }
    else
    {
        sumDown = -2;
        downFlag = false;
    }

    // check left
    if (move('L'))
    {
        board.findCosts(&movedUp, &movedDown, &movedLeft, &movedRight);
        sumLeft = (initLeft - movedRight);
        move('R');
        numberOfMoves-=2;
    }
    else
    {
        sumLeft = -2;
        leftFlag = false;
    }

    // check right
    if (move('R'))
    {
        board.findCosts(&movedUp, &movedDown, &movedLeft, &movedRight);
        sumRight = (initRight - movedLeft);
        move('L');
        numberOfMoves-=2;
    }
    else
    {
        sumRight = -2;
        rightFlag = false;
    }

    // find and count maximums
    int maxMan = BasicUtils::max4(sumUp, sumDown, sumLeft, sumRight);
    int countMaxes = 0;
    if (upFlag && maxMan == sumUp)
    {
        maxUp = true;
        countMaxes++;
    }
    if (downFlag && maxMan == sumDown)
    {
        maxDown = true;
        countMaxes++;
    }
    if (leftFlag && maxMan == sumLeft)
    {
        maxLeft = true;
        countMaxes++;
    }
    if (rightFlag && maxMan == sumRight)
    {
        maxRight = true;
        countMaxes++;
    }

    // if maximum is -1 or ther is no maximum board is stuck
    if(countMaxes == 0 || maxMan == -1) {
        std::cout << "randomly " << moveRandom() << std::endl;
        std::cout << "AI choosed randomly " << moveRandom() << std::endl;
        std::cout << "AI choosed randomly " << moveRandom() << std::endl;
        std::cout << "AI choosed randomly " << moveRandom() << std::endl;
        std::cout << "AI choosed randomly " << moveRandom() << std::endl;
        return;
    }

    // if there is only one max, move there
    if (countMaxes == 1)
    {
        if (maxUp)
        {
            std::cout << "up\n";
            move('U');
            return;
        }
        if (maxDown)
        {
            std::cout << "down\n";
            move('D');
            return;
        }
        if (maxLeft)
        {
            std::cout << "left\n";
            move('L');
            return;
        }
        if (maxRight)
        {
            std::cout << "right\n";
            move('R');
            return;
        }
    }
    else
    {
        // if there are more than one maximums, select randomly between maxes
        int randomNum = 0;
        while (true)
        {
            randomNum = BasicUtils::randBetween(0, 3);
            switch (randomNum)
            {
            case 0:
                if (maxUp)
                {
                    std::cout << "up\n";
                    move('U');
                    return;
                }
                break;
            case 1:
                if (maxDown)
                {
                    std::cout << "down\n";
                    move('D');
                    return;
                }
                break;
            case 2:
                if (maxLeft)
                {
                    std::cout << "left\n";
                    move('L');
                    return;
                }
                break;
            case 3:
                if (maxRight)
                {
                    std::cout << "right\n";
                    move('R');
                    return;
                }
                break;

            default:
                break;
            }
        }
    }
}

bool NPuzzle::move(char move)
{
    bool success = board.move(move);
    if (success)
        numberOfMoves++;
    return success;
}

bool NPuzzle::solvePuzzle()
{
    bool success = true;
    int moves = 0;
    while (!board.isSolved())
    {
        moveIntelligent();
        moves++;
        if (moves > AI_LIMIT)
        {
            success = false;
            break;
        }
    }
    printReport();
    return success;
}
