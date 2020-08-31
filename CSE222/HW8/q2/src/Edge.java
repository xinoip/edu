
/**
 * Representing Edges inside Graph
 */
public class Edge {

    /**
     * Destination node
     */
    private int dest;
    /**
     * Source node
     */
    private int source;

    /**
     * Weight of edge
     */
    private double weight;

    /**
     * Constructor for creating weighted edge
     * 
     * @param source source node
     * @param dest destination node
     * @param w weight of edge
     */
    public Edge(int source, int dest, double w) {
        this.source = source;
        this.dest = dest;
        this.weight = w;
    }

    /**
     * Constructor for creating edge with weight of 1
     * 
     * @param source source node
     * @param dest destination node
     */
    public Edge(int source, int dest) {
        this(source, dest, 1.0);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Edge))
            return false;

        Edge otherEdge = (Edge) obj;

        return (this.dest == otherEdge.dest && this.source == otherEdge.source);
    }

    /**
     * Getter for destination node
     * 
     * @return destination node
     */
    public int getDest() {
        return this.dest;
    }

    /**
     * Getter for source node
     * 
     * @return source node
     */
    public int getSource() {
        return this.source;
    }

    /**
     * Getter for weight of edge
     * 
     * @return weight of edge
     */
    public double getWeight() {
        return this.weight;
    }

    @Override
    public int hashCode() {
        int hash = 5;

        hash = 31 * hash + dest;
        hash = 31 * hash + source;

        return hash;
    }

    @Override
    public String toString() {
        return String.format("Edge[dest=%d, source=%d, weight=%f]", dest, source, weight);
    }
}