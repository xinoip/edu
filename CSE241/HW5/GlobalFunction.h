#include "AbstractBoard.h"

bool isValidSequence(bugra::AbstractBoard *arr[], int length)
{
    const int EMPTY = -1;
    int currentEmptyRow, currentEmptyCol;
    int nextEmptyRow, nextEmptyCol;
    unsigned int sizeRow, sizeCol;

    for (int i = 0; i < length - 1; i++)
    {
        arr[i]->getSize(sizeRow, sizeCol);
        for (int j = 0; j < sizeRow; j++)
        {
            for (int k = 0; k < sizeCol; k++)
            {
                if ((*arr[i])(j, k) == EMPTY)
                {
                    currentEmptyRow = j;
                    currentEmptyCol = k;
                }
            }
        }

        arr[i + 1]->getSize(sizeRow, sizeCol);
        for (int j = 0; j < sizeRow; j++)
        {
            for (int k = 0; k < sizeCol; k++)
            {
                if ((*arr[i + 1])(j, k) == EMPTY)
                {
                    nextEmptyRow = j;
                    nextEmptyCol = k;
                }
            }
        }

        int diffRow = abs(nextEmptyRow - currentEmptyRow);
        int diffCol = abs(nextEmptyCol - currentEmptyCol);
        if ((diffCol == 1 && diffRow == 0) || (diffRow == 1 && diffCol == 0) )
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}