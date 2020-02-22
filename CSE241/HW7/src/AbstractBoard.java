

import java.io.*;
import java.util.Scanner;

/**
 * <h1>AbstractBoard</h1>
 */
public abstract class AbstractBoard {
	protected static int _numberOfBoards;
	protected int _numberOfMoves;
	protected char _lastMove;
	protected int _rowSize, _colSize;
	
	/**
	 * Return board content at (row,col).
	 * 
	 * @param coordinate
	 * @return int value at cell
	 */
	public abstract int cell(int row, int col);

	/**
	 * Set board content at (row,col).
	 * 
	 * @param coordinate
	 * @param val the new value
	 */
	public abstract void setCell(int row, int col, int val);

	/**
	 * Resize the board with new row and col.
	 * 
	 * @param row new row size
	 * @param col new column size
	 */
	public abstract void resize(int row, int col);

	/**
	 * Resize the board and then reset to solution.
	 * 
	 * @param row new row size
	 * @param col new column size
	 */
	public void setSize(int row, int col) {
		resize(row, col);
		reset();
	}

	public int getRowSize() {
		return _rowSize;
	}

	public int getColSize() {
		return _colSize;
	}

	public void print() {
		System.out.printf(this.toString());
	}

	/**
	 * Return board as a string
	 * 
	 * @return String board representation
	 */
	@Override
	public String toString() {
		final int EMPTY = -1;
		final int BLOCK = -2;
		
		String rtr = "";
		
		int currentTile = 0;
		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _colSize; j++) {
				currentTile = cell(i, j);

				if (currentTile == EMPTY) {
					rtr += "__";

				} else if (currentTile == BLOCK) {
					rtr += "WW";

				} else {
					rtr += currentTile;

				}

				// Check number of digits for alignment of board
				if (currentTile / 10 <= 0 && currentTile != EMPTY && currentTile != BLOCK) {
					rtr += "  ";

				} else {
					rtr += " ";

				}

			}
			rtr += "\n";

		}
		return rtr;
	}
	
	
	/**
	 * Read from given java File.
	 * 
	 * @param file java.io.file
	 * @see java.io.file
	 * @return boolean result indicating success
	 */
	public boolean readFromFile(File file) {
		final int EMPTY = -1;
		final int BLOCK = -2;

		try {
			Scanner sizer = new Scanner(file);
			sizer.useDelimiter("");

			char currChar;
			int currRow = 0, currCol = 0;
			int firstDigit, secondDigit, currNum;

			// Get size of the array
			int rowSize, colSize = 0;
			while (sizer.hasNext()) {
				currChar = sizer.next().charAt(0);

				switch (currChar) {
				case ' ':
					currCol++;
					break;
				case '\n':
					colSize = currCol + 1;
					currRow++;
					currCol = 0;
					break;
				case 'b':
					currChar = sizer.next().charAt(0);
					break;

				default:
					currChar = sizer.next().charAt(0);
					break;
				}
			}
			rowSize = currRow + 1;

			// Set new size and go back
			resize(rowSize, colSize);

			sizer.close();
			Scanner reader = new Scanner(file);
			reader.useDelimiter("");

			currRow = 0;
			currCol = 0;
			// Read and place contents of the array
			while (reader.hasNext()) {
				currChar = reader.next().charAt(0);

				switch (currChar) {
				case ' ':
					currCol++;
					break;
				case '\n':
					currRow++;
					currCol = 0;
					break;
				case 'b':
					currChar = reader.next().charAt(0);
					setCell(currRow, currCol, EMPTY);
					break;

				default:
					firstDigit = currChar - '0';
					currChar = reader.next().charAt(0);
					secondDigit = currChar - '0';
					currNum = firstDigit * 10 + secondDigit;

					if (currNum == 0) {
						setCell(currRow, currCol, BLOCK);
					} else {
						setCell(currRow, currCol, currNum);
					}
					break;
				}
			}

			reader.close();

		} catch (IOException e) {
			System.err.print("File error: " + file.getName());
			e.printStackTrace();
			return false;

		}

		return true;
	}

	/**
	 * Write to given java file.
	 * 
	 * @param file java.io.file
	 * @see java.io.file
	 * @return boolean result indicating success
	 */
	public boolean writeToFile(File file) {
		final int EMPTY = -1;
		final int BLOCK = -2;

		try {
			FileWriter writer = new FileWriter(file);

			int currentTile = 0;
			for (int i = 0; i < _rowSize; i++) {
				for (int j = 0; j < _colSize; j++) {
					currentTile = cell(i, j);

					if (currentTile == EMPTY) {
						writer.write("bb");
					} else if (currentTile == BLOCK) {
						writer.write("00");
					} else {
						if (currentTile / 10 < 1) {
							writer.write("0");
							writer.write(Integer.toString(currentTile));
						} else {
							writer.write(Integer.toString(currentTile));
						}
					}

					if (j != _colSize - 1) {
						writer.write(" ");
					}
				}
				if (i != _rowSize - 1) {
					writer.write(System.getProperty("line.separator"));

				}
			}

			writer.close();

		} catch (IOException e) {
			System.err.print("File error: " + file.getName());
			e.printStackTrace();
			return false;

		}

		return true;
	}

	/**
	 * Reset board to solution.
	 */
	public void reset() {
		final int EMPTY = -1;
		final int BLOCK = -2;
		int currCorrect = 1;

		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _colSize; j++) {
				if (cell(i, j) != BLOCK) {
					setCell(i, j, currCorrect);
					currCorrect++;
				}

			}

		}
		setCell(_rowSize - 1, _colSize - 1, EMPTY);

		_numberOfMoves = 0;
		_lastMove = 'S';
	}

	/**
	 * Move empty cell to given direction.
	 * 
	 * @param move 'U'p 'D'own 'L'eft 'R'ight
	 * @return boolean didMove
	 */
	public boolean move(char move) {
		final int EMPTY = -1;
		final int BLOCK = -2;
		boolean isMoved = false;

		int emptyTileRow = 0, emptyTileCol = 0;
		boolean foundEmpty = false;
		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _colSize; j++) {
				if (cell(i, j) == EMPTY) {
					emptyTileRow = i;
					emptyTileCol = j;
					foundEmpty = true;
					break;
				}
			}
			if (foundEmpty)
				break;
		}

		if (!foundEmpty) {
			System.out.println("There are no empty tile to move!");
			return isMoved;
		}

		int newRow = emptyTileRow, newCol = emptyTileCol;
		switch (move) {
		case 'L':
			if (cell(newRow, newCol - 1) != BLOCK && emptyTileCol != 0) {
				newCol--;
				isMoved = true;
			}
			break;
		case 'R':
			if (cell(newRow, newCol + 1) != BLOCK && emptyTileCol != _colSize - 1) {
				newCol++;
				isMoved = true;
			}
			break;

		case 'U':
			if (cell(newRow - 1, newCol) != BLOCK && emptyTileRow != 0) {
				newRow--;
				isMoved = true;
			}
			break;

		case 'D':
			if (cell(newRow + 1, newCol) != BLOCK && emptyTileRow != _rowSize - 1) {
				newRow++;
				isMoved = true;
			}
			break;
		default:
			break;
		}
		if (isMoved) {
			int tmp = cell(emptyTileRow, emptyTileCol);
			setCell(emptyTileRow, emptyTileCol, cell(newRow, newCol));
			setCell(newRow, newCol, tmp);
			emptyTileRow = newRow;
			emptyTileCol = newCol;
			_numberOfMoves++;
			_lastMove = move;
		}

		return isMoved;
	}

	/**
	 * Check the board state for solution.
	 * 
	 * @return boolean isSolved
	 */
	public boolean isSolved() {
		final int EMPTY = -1;
		final int BLOCK = -2;
		int currCorrect = 1;
		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _colSize; j++) {
				if (cell(i, j) != BLOCK) {
					if (cell(i, j) != EMPTY && cell(i, j) != currCorrect) {
						return false;

					}
					currCorrect++;

				}

			}

		}
		return true;
	}

	/**
	 * Check equality against given board.
	 * 
	 * @param board otherBoard
	 * @return boolean isEqual
	 */
	public boolean Equals(AbstractBoard board) {
		final int otherRowSize = board._rowSize;
		final int otherColSize = board._colSize;

		if (otherColSize == _colSize && otherRowSize == _rowSize) {
			for (int i = 0; i < _rowSize; i++) {
				for (int j = 0; j < _colSize; j++) {
					if (board.cell(i, j) != cell(i, j)) {
						return false;

					}

				}

			}

		} else {
			return false;

		}

		return true;
	}

	public int NumberOfBoards() {
		return _numberOfBoards;
	}

	public char lastMove() {
		return _lastMove;
	}

	public int numberOfMoves() {
		return _numberOfMoves;
	}
}
