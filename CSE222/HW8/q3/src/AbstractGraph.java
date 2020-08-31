import java.util.*;

/**
 * Abstract base class for graphs. A graph is a set of vertices and a set of
 * edges. Vertices are represented by integers from 0 to n - 1. Edges are
 * ordered pairs of vertices.
 * 
 * Taken from book, but implemented the loading method from file, by myself.
 */
public abstract class AbstractGraph implements Graph {
    // Data Fields
    /** The number of vertices */
    private int numV;
    /** Flag to indicate whether this is a directed graph */
    private boolean directed;

    // Constructor
    /**
     * Construct a graph with the specified number of vertices and the directed
     * flag. If the directed flag is true, this is a directed graph.
     * 
     * @param numV     The number of vertices
     * @param directed The directed flag
     */
    public AbstractGraph(int numV, boolean directed) {
        this.numV = numV;
        this.directed = directed;
    }

    // Accessor Methods
    /**
     * Return the number of vertices.
     * 
     * @return The number of vertices
     */
    public int getNumV() {
        return numV;
    }

    /**
     * Return whether this is a directed graph.
     * 
     * @return true if this is a directed graph
     */
    public boolean isDirected() {
        return directed;
    }

    // Other Methods
    /**
     * Load the edges of a graph from the data in an input file. The file should
     * contain a series of lines, each line with two or three data values. The first
     * is the source, the second is the destination, and the optional third is the
     * weight.
     * 
     * Implemented By Me
     * 
     * @param scan The Scanner connected to the data file
     */
    public void loadEdgesFromFile(Scanner scan) {
        while(scan.hasNext()) {
            int src = scan.nextInt();
            int dest = scan.nextInt();
            int weight = scan.nextInt();

            Edge edge = new Edge(src, dest, weight);
            this.insert(edge);
        }
    }

    /**
     * Factory method to create a graph and load the data from an input file. The
     * first line of the input file should contain the number of vertices. The
     * remaining lines should contain the edge data as described under
     * loadEdgesFromFile.
     * 
     * @param scan       The Scanner connected to the data file
     * @param isDirected true if this is a directed graph, false otherwise
     * @param type       The string "Matrix" if an adjacency matrix is to be
     *                   created, and the string "List" if an adjacency list is to
     *                   be created
     * @throws IllegalArgumentException if type is neither "Matrix" nor "List"
     */
    public static Graph createGraph(Scanner scan, boolean isDirected, String type) {
        int numV = scan.nextInt();
        AbstractGraph returnValue;
        type = type.toLowerCase();
        switch (type) {
            case "list":
                returnValue = new ListGraph(numV, isDirected);
                break;
            default:
                throw new IllegalArgumentException();
        }
        returnValue.loadEdgesFromFile(scan);
        return returnValue;
    }
}