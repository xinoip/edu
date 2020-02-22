#ifndef NPuzzle_h
#define NPuzzle_h

//#include "./Board.h"

#include <iostream>
#include <fstream>
#include "BasicUtils.h"

class NPuzzle
{
public:
    void print() const;
    void printReport() const;
    bool readFromFile(const char *fileName);
    void writeToFile(const char *fileName) const;
    void shuffle(int n);
    void reset();
    void setSize(int width, int height);
    char moveRandom();
    void moveIntelligent();
    bool move(char move);
    bool solvePuzzle();

private:
    class Board
    {
    public:
        Board();
        void print() const;
        bool readFromFile(const char *fileName);
        void writeToFile(const char *fileName) const;
        void reset();
        void setSize(int width, int height);
        bool move(char move);
        bool isSolved() const;

        /**
         * Finds the expected place for given value and returns it.
         */
        void findExpectedPlace(int value, int *row, int *col) const;
        /**
         * Finds the manhattan distance for given position and returns it.
         */
        int findManhattan(int row, int col) const;
        /**
         * Finds the costs around empty space, returns every directions cost.
         */
        void findCosts(int *up, int *down, int *left, int *right) const;

    private:
        int arr[9][9];
        int width, height;
        int emptyTileRow, emptyTileCol;
        const int EMPTY = -1;
        const int BLOCK = -2;
    } board;
    int numberOfMoves = 0;
    const int AI_LIMIT = 800000;
    const int NUMBER_OF_SHUFFLES = 30;
};

#endif