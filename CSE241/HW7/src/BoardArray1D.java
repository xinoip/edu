


/**
 * <h1>BoardArray1D</h1>
 */
public class BoardArray1D extends AbstractBoard {
	private int[] data;
	
	@Override
	public int cell(int row, int col) {
		final int BLOCK = -2;
		if (row >= 0 && col >= 0 && row < _rowSize && col < _colSize) {
			return data[(row * _colSize) + col];
		} else {
			return BLOCK;
		}
	}

	@Override
	public void setCell(int row, int col, int val) {
		if (row >= 0 && col >= 0 && row < _rowSize && col < _colSize) {
			data[(row * _colSize) + col] = val;
		}
	}

	@Override
	public void resize(int row, int col) {
		data = new int[row * col];
		_rowSize = row;
		_colSize = col;
	}

}
