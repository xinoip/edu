/**
 * Class for representing a vertex inside Maze, it is used mainly for
 * representing junctions.
 */
public class MazeVertex {
    /**
     * Row coordinate inside 2d maze
     */
    private int row;
    /**
     * Col coordinate inside 2d maze
     */
    private int col;
    /**
     * Value from the maze, expecting 0 for empty spaces, other values will be
     * ignored
     */
    private int value;

    /**
     * Copy constructor, copies the vertex from given vertex
     * 
     * @param vertex vertex to copy from
     */
    MazeVertex(MazeVertex vertex) {
        this.row = vertex.row;
        this.col = vertex.col;
        this.value = vertex.value;
    }

    /**
     * Create MazeVertex from coordinates, without value
     * 
     * @param row row coordinate
     * @param col col coordinate
     */
    public MazeVertex(int row, int col) {
        this.row = row;
        this.col = col;
    }

    /**
     * Create MazeVertex from coordinates, with value
     * 
     * @param row row coordinate
     * @param col col coordinate
     * @param value value of vortex from maze
     */
    public MazeVertex(int row, int col, int value) {
        this.row = row;
        this.col = col;
        this.value = value;
    }

    /**
     * Setter for value
     * 
     * @param value vertex new value
     */
    public void setValue(int value) {
        this.value = value;
    }

    /**
     * Returns true if the vertex value is 0, false otherwise
     * 
     * @return empty vertex or not
     */
    public boolean isEmpty() {
        return value == 0;
    }

    /**
     * Getter for row
     * 
     * @return row coordinate
     */
    public int getRow() {
        return row;
    }

    /**
     * Getter for col
     * 
     * @return col coordinate
     */
    public int getCol() {
        return col;
    }

    /**
     * Moves the vertex to left
     * It does the necessary row,col arithmetics
     */
    public void goLeft() {
        col--;
    }

    /**
     * Moves the vertex to right
     * It does the necessary row,col arithmetics
     */
    public void goRight() {
        col++;
    }

    /**
     * Moves the vertex to top
     * It does the necessary row,col arithmetics
     */
    public void goTop() {
        row--;
    }

    /**
     * Moves the vertex to bottom
     * It does the necessary row,col arithmetics
     */
    public void goBottom() {
        row++;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof MazeVertex))
            return false;

        MazeVertex other = (MazeVertex) obj;

        return this.row == other.row && this.col == other.col;
    }

    @Override
    public String toString() {
        return String.format("(%d,%d)", row, col);
    }
}