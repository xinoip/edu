#ifndef NPuzzle_h
#define NPuzzle_h

//#include "./Board.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "BasicUtils.h"

class NPuzzle
{
public:
    NPuzzle();
    void print() const;
    void printReport() const;
    bool readFromFile(std::ifstream &boardFile);
    void writeToFile(const char *fileName) const;
    void shuffle();
    void reset();
    void setSize(int width, int height);
    char moveRandom();
    bool move(char move);
    bool solvePuzzle();

    void printSolution();

    friend std::ostream &operator<<(std::ostream &os, const NPuzzle &puzzle);
    friend std::istream &operator>>(std::istream &is, NPuzzle &puzzle);

private:
    class Board
    {
    public:
        Board();
        void print() const;
        bool readFromFile(std::ifstream& boardFile);
        void writeToFile(const char *fileName) const;
        void reset();
        void setSize(int width, int height);
        bool move(char move);
        bool isSolved() const;

        // stored number of boards as a static integer
        // this acts like a counter for every created instance of this class
        // i incremented that counter in constructor of the class
        int NumberOfBoards();

        int getNumberOfMoves() const;
        void setNumberOfMoves(int value);
        int getWidth() const;
        int getHeight() const;
        int getEmptyTileRow() const;
        int getEmptyTileCol() const;
        char getLastMove() const;
        void setLastMove(char value);

        int operator()(int row, int col) const;
        bool operator==(const Board &board) const;

        // basic assignment operator for copying boards
        void operator=(Board &board) const;

    private:
        //int arr[9][9];
        std::vector<std::vector<int>> arr;

        int width, height;
        int emptyTileRow, emptyTileCol;
        const int EMPTY = -1;
        const int BLOCK = -2;

        char lastMove;
        int numberOfMoves = 0;

        static int noBoards;
    };
    std::vector<Board> boards;
    const int AI_LIMIT = 800000;
    int numberOfShuffles;
};

#endif