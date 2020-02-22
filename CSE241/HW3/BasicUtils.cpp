#include "./BasicUtils.h"

void BasicUtils::swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int BasicUtils::max4(int a, int b, int c, int d)
{
    if (a >= b && a >= c && a >= d)
        return a;
    else if (b >= a && b >= c && b >= d)
        return b;
    else if (c >= a && c >= b && c >= d)
        return c;
    else
        return d;
}

int BasicUtils::randBetween(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int BasicUtils::getIntInput(int start, int end)
{
    bool success = false;
    int input = 0;

    do
    {
        std::cin >> input;
        if (!std::cin.fail())
        {
            if (input >= start && input <= end)
            {
                success = true;
            }
            else
            {
                std::cout << "You can only enter between " << start << " and " << end << "\n";
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "You can only enter a number!\n";
        }

    } while (!success);

    return input;
}
