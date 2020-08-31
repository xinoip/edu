import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * AbstractMazeSolver is basic base for all possible MazeSolver implementations
 * It standarizes the constuction process and getting the input file into a 2d
 * array. It provides basic methods for analyzing the positions inside this
 * input file like isValidPositions, get left top right bottom, is junction
 * methods
 * 
 * However it does not meddle with graphs, it is left to the programmer who
 * extends this class to construct the correct graph and provide the shortest
 * path for that graph.
 */
public abstract class AbstractMazeSolver implements MazeSolver {
    /**
     * Input file is just 2d array of digits, this represents the input file as 2d
     * list structure
     */
    protected List<List<Integer>> mazeInput;
    /**
     * Start of the maze, should always be (0,0)
     */
    protected MazeVertex startVertex;
    /**
     * End of the maze, should always be bottom right corner
     */
    protected MazeVertex endVertex;

    /**
     * Creates the MazeSolver from given file input The file input should consist a
     * 2d array of digits
     * 
     * @param file input for MazeSolver
     * @throws FileNotFoundException if the file not existent
     */
    public AbstractMazeSolver(File file) throws FileNotFoundException {
        this.mazeInput = new ArrayList<>();
        this.startVertex = new MazeVertex(0, 0, 0);
        this.constructMazeFromFile(file);
        this.endVertex = new MazeVertex(mazeInput.size() - 1, mazeInput.get(0).size() - 1, 0);
    }

    /**
     * Helper method for constructing maze from file It does the necessary scanning
     * and parsing process and converts the input file into 2d list structure
     * 
     * @param file input file for MazeSolver
     * @throws FileNotFoundException if the file not existent
     */
    private void constructMazeFromFile(File file) throws FileNotFoundException {
        Scanner scan = new Scanner(file);
        int currentLine = 0;
        while (scan.hasNextLine()) {
            String line = scan.nextLine();

            char[] lineChars = line.toCharArray();
            mazeInput.add(new ArrayList<>());
            for (char c : lineChars) {
                mazeInput.get(currentLine).add(c - '0');
            }
            currentLine++;
        }
        scan.close();
    }

    /**
     * Finds the given vertex inside input of MazeSolver If it is valid, returns the
     * value of it from input If not valid, returns -1
     * 
     * @param vertex target vertex
     * @return valid value or -1
     */
    protected int getMazeValue(MazeVertex vertex) {
        if (isValidVertex(vertex)) {
            return mazeInput.get(vertex.getRow()).get(vertex.getCol());
        }

        return -1;
    }

    /**
     * Calculates the left top right bottom MazeVertices of given Vertex, as a list.
     * It eases the process of getting surroandings of a point inside maze input
     * 
     * @param vertex source vertex to look from
     * @return left, top, right, bottom vertices from source vertex, as a MazeVertex
     *         list
     */
    protected List<MazeVertex> ltrbVertices(MazeVertex vertex) {
        List<MazeVertex> rtr = new ArrayList<>();

        MazeVertex left = new MazeVertex(vertex);
        left.goLeft();
        left.setValue(getMazeValue(left));
        MazeVertex top = new MazeVertex(vertex);
        top.goTop();
        top.setValue(getMazeValue(top));
        MazeVertex right = new MazeVertex(vertex);
        right.goRight();
        right.setValue(getMazeValue(right));
        MazeVertex bottom = new MazeVertex(vertex);
        bottom.goBottom();
        bottom.setValue(getMazeValue(bottom));

        rtr.add(left);
        rtr.add(top);
        rtr.add(right);
        rtr.add(bottom);
        return rtr;
    }

    /**
     * Cheks if the given vertex can exist in the current maze input. It mainly
     * checks the bounds of 2d list structure.
     * 
     * @param vertex vertex to check for
     * @return true if it can exist in current maze, false otherwise
     */
    protected boolean isValidVertex(MazeVertex vertex) {
        if (vertex.getRow() < mazeInput.size() && vertex.getRow() >= 0) {
            if (vertex.getCol() < mazeInput.get(0).size() && vertex.getCol() >= 0) {
                return true;
            }
        }

        return false;
    }

    /**
     * Checks if the given vertex is a junction in the current maze input. A
     * junction is the connection points in maze. Instead of creating graph from
     * every position inside maze, the better approach is to create the graph from
     * this junction points.
     * 
     * @param vertex target vertex to check
     * @return true if its junction, false otherwise
     */
    protected boolean isJunctionVertex(MazeVertex vertex) {
        if (!this.isValidVertex(vertex) || !vertex.isEmpty())
            return false;

        if (vertex.equals(startVertex) || vertex.equals(endVertex))
            return true;

        List<MazeVertex> ltrb = ltrbVertices(vertex);
        MazeVertex left = ltrb.get(0);
        MazeVertex top = ltrb.get(1);
        MazeVertex right = ltrb.get(2);
        MazeVertex bottom = ltrb.get(3);

        int emptyCount = 0;
        if (left.isEmpty()) {
            emptyCount++;
        }
        if (top.isEmpty()) {
            emptyCount++;
        }
        if (right.isEmpty()) {
            emptyCount++;
        }
        if (bottom.isEmpty()) {
            emptyCount++;
        }

        if (emptyCount == 2) {
            if (left.isEmpty() && right.isEmpty()) {
                return false;
            }
            if (top.isEmpty() && bottom.isEmpty()) {
                return false;
            }
            return true;
        } else if (emptyCount != 0 && emptyCount != 1) {
            return true;
        } else {
            return false;
        }
    }

}