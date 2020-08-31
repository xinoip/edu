
/**
 * Maze Solver interface is for solvable graphs. It is just for finding shortest
 * path and printing it.
 */
public interface MazeSolver {
    /**
     * Finds the shortest path from graph. Returns a string consisting of shortest
     * path coordinates.
     * 
     * @return Shortest path from (0,0) to (size-1, size-1) linked together
     */
    String shortestPath();

    /**
     * Showing that the edges are only from junction to junction
     * 
     * @return all edges
     */
    String allEdges();

    /**
     * Classes that implementing this interface needs to construct the graph and
     * provide it via this method
     * 
     * @return graph representation of maze
     */
    Graph getGraph();
}