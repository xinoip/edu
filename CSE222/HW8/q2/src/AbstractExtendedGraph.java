
/**
 * Extended version of AbstractGraph that also can delete insert vertices and delete edges
 */
public abstract class AbstractExtendedGraph extends AbstractGraph {
    public AbstractExtendedGraph(int numV, boolean directed) {
        super(numV, directed);
    }

    /**
     * Finds and deletes given edge, returns true on success
     * 
     * @param edge edge to delete
     * @return success status
     */
    public abstract boolean deleteEdge(Edge edge);

    /**
     * Inserts given vertex
     * 
     * @param vertex vertex to insert
     */
    public abstract void insertVertex(int vertex);

    /**
     * Deletes given vertex
     * 
     * @param vertex vertex to delete
     */
    public abstract void deleteVertex(int vertex);

    /**
     * Breadth first printing
     */
    public abstract void bfs();

    /**
     * Depth first printing
     */
    public abstract void dfs();
}