


/**
 * <h1>BoardArray2D</h1>
 */
public class BoardArray2D extends AbstractBoard {
	private int[][] data;

	public BoardArray2D() {
		_colSize = 4;
	    _rowSize = 4;

	    // Allocate new array with new sizes
	    data = new int[_rowSize][_colSize];
	    
	    _numberOfBoards++;
	    // Reset to solution
	    reset();
	}
	
	@Override
	public int cell(int row, int col) {
		final int BLOCK = -2;
		if (row >= 0 && col >= 0 && row < _rowSize && col < _colSize) {
			return data[row][col];
		} else {
			return BLOCK;
		}
	}

	@Override
	public void setCell(int row, int col, int val) {
		if (row >= 0 && col >= 0 && row < _rowSize && col < _colSize) {
			data[row][col] = val;
		}
	}

	@Override
	public void resize(int row, int col) {
		data = new int[row][col];
		
//		int[][] temp = new int[row][col];
//		for (int i = 0; i < _rowSize; i++) {
//			System.arraycopy(data[i], 0, temp[i], 0, col);
//		}
//		data = temp;
		_rowSize = row;
		_colSize = col;
	}

}
