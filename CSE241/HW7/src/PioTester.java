

import java.io.File;

/**
 * <h1>PioTester</h1>
 * <p>
 * Various tests for boards.
 * </p>
 * <ul>
 * <li>Valid Sequence Test</li>
 * <li>General Test</li>
 * </ul>
 *
 */
public class PioTester {

	/**
	 * Check if the given array is a valid sequence regarding the movement pattern.
	 * 
	 * @param arr various boards in form of AbstractBoard array.
	 * @return boolean result for validity.
	 */
	public static boolean isValidSequence(AbstractBoard arr[]) {
		final int EMPTY = -1;
		int currentEmptyRow = 0, currentEmptyCol = 0;
		int nextEmptyRow = 0, nextEmptyCol = 0;
		int sizeRow, sizeCol;

		for (int i = 0; i < arr.length - 1; i++) {
			sizeRow = arr[i].getRowSize();
			sizeCol = arr[i].getColSize();
			for (int j = 0; j < sizeRow; j++) {
				for (int k = 0; k < sizeCol; k++) {
					if (arr[i].cell(j, k) == EMPTY) {
						currentEmptyRow = j;
						currentEmptyCol = k;
					}
				}
			}

			sizeRow = arr[i + 1].getRowSize();
			sizeCol = arr[i + 1].getColSize();

			for (int j = 0; j < sizeRow; j++) {
				for (int k = 0; k < sizeCol; k++) {
					if (arr[i + 1].cell(j, k) == EMPTY) {
						nextEmptyRow = j;
						nextEmptyCol = k;
					}
				}
			}

			int diffRow = Math.abs(nextEmptyRow - currentEmptyRow);
			int diffCol = Math.abs(nextEmptyCol - currentEmptyCol);
			if ((diffCol == 1 && diffRow == 0) || (diffRow == 1 && diffCol == 0)) {
			} else {
				return false;
			}
		}
		return true;
	}

	/**
	 * Do the following tests for given array:
	 * <ol>
	 * <li>setSize to 4x4 and print</li>
	 * <li>setSize to 24x22 and print</li>
	 * <li>writeToFile</li>
	 * <li>readFromFile called testRead.txt and print</li>
	 * <li>reset to solution and print</li>
	 * <li>test isSolved and print</li>
	 * <li>print member values of board</li>
	 * </ol>
	 * 
	 * @param arr various boards in form of AbstractBoard array.
	 * @param testNo given test number will change output files name.
	 * @return boolean result for validity.
	 */
	public static void testBoard(AbstractBoard board, String testNo) {
		File ifile = new File("../testRead.txt");
		File ofile = new File("testOut" + testNo + ".txt");

		System.out.printf("\n\n\nBasic setSize and printing: \n");
		board.setSize(4, 4);
		board.print();

		System.out.printf("Dynamic alloc demo, big board: \n");
		board.setSize(24, 22);
		board.print();

		System.out.printf("Writing to file...\n");
		board.writeToFile(ofile);
		System.out.printf("Write to file done: testOut.txt\n\n");

		System.out.printf("Reading from file...\n");
		board.readFromFile(ifile);
		System.out.printf("Read file done: testRead.txt, printing: \n");
		board.print();

		System.out.printf("\nReseting board that has walls in it: \n");
		board.reset();
		System.out.printf("Reset done, printing: \n");
		board.print();

		// after reset it should be solved
		System.out.printf("Testing isSolved: \n");
		if (board.isSolved()) {
			System.out.printf("isSolved test passed! \n");
		} else {
			System.out.printf("isSolved test failed! \n");
		}

		System.out.printf("Testing getters: \n");
		System.out.printf("NumberOfBoards: " + board.NumberOfBoards() + "\n");
		System.out.printf("lastMove: " + board.lastMove() + "\n");
		System.out.printf("numberOfMoves: " + board.numberOfMoves() + "\n");

		System.out.printf("\nTest done, check files and results!\n\n-\n\n");
	}

}
