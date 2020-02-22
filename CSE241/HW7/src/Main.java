


/**
 * <h1>Homework 7</h1>
 * <p>
 * Board class hierarchy for CSE241 at GTU
 * </p>
 *
 * @author Buğra Eren Yılmaz
 * @version 1.0
 * @since 2020-01-16
 */
public class Main {

	/**
	 * The main method running tests.
	 * 
	 * @param args Unused.
	 * @return Nothing.
	 */
	public static void main(String[] args) {
		BoardArray1D board1 = new BoardArray1D();
		BoardArray2D board = new BoardArray2D();

		PioTester.testBoard(board, "1");
		PioTester.testBoard(board1, "1DTEST");

		validSequenceTest();
	}

	/**
	 * The sequence tester method.
	 * Calls to PioTester.
	 * 
	 * @see PioTester
	 * @return Nothing.
	 */
	public static void validSequenceTest() {
		AbstractBoard[] boards = new AbstractBoard[5];
		boards[0] = new BoardArray1D();
		boards[1] = new BoardArray1D();
		boards[2] = new BoardArray2D();
		boards[3] = new BoardArray2D();
		boards[4] = new BoardArray2D();

		for (int i = 0; i < 5; i++) {
			boards[i].setSize(5, 5);
		}
		System.out.printf("Board 0: \n");
		boards[0].print();

		boards[1].move('L');
		System.out.printf("Board 1: \n");
		boards[1].print();

		boards[2].move('L');
		boards[2].move('U');
		System.out.printf("Board 2: \n");
		boards[2].print();
		System.out.printf("\n");

		boards[3].move('L');
		boards[3].move('U');
		boards[3].move('R');
		System.out.printf("Board 3: \n");
		boards[3].print();
		System.out.printf("\n");

		boards[4].move('L');
		boards[4].move('U');
		boards[4].move('R');
		boards[4].move('U');
		System.out.printf("Board 4: \n");
		boards[4].print();

		if (PioTester.isValidSequence(boards)) {
			System.out.printf("\n\nValid sequence!\n");
		} else {
			System.out.printf("\n\nNot Valid sequence!\n");
		}

	}
}
