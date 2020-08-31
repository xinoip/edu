/**
 * Class for representing a pathway connection inside Maze
 */
public class MazeEdge {
    /**
     * Source vertex
     */
    private MazeVertex src;
    /**
     * Destination vertex
     */
    private MazeVertex dest;
    /**
     * Length of the pathway, in other words weight of that edge in graph
     */
    private int weight;

    /**
     * Creates MazeEdge from src and dest vertex with given weight
     * 
     * @param src    source vertex
     * @param dest   destination vertex
     * @param weight length of pathway
     */
    public MazeEdge(MazeVertex src, MazeVertex dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    /**
     * Getter for source vertex
     * 
     * @return source vertex
     */
    public MazeVertex getSrc() {
        return src;
    }

    /**
     * Getter for destination vertex
     * 
     * @return destination vertex
     */
    public MazeVertex getDest() {
        return dest;
    }

    /**
     * Getter for weight of pathway
     * 
     * @return weight of pathway
     */
    public int getWeight() {
        return weight;
    }

    /**
     * Symetric version of MazeEdge, it returns a new MazeEdge which is just dest
     * and src swapped version.
     * 
     * @return symmetric of the MazeEdge as ne MazeEdge
     */
    public MazeEdge symetric() {
        return new MazeEdge(dest, src, weight);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof MazeEdge))
            return false;

        MazeEdge other = (MazeEdge) obj;

        return this.src.equals(other.src) && this.dest.equals(other.dest);
    }

    @Override
    public String toString() {
        return String.format("%s -> %s :(%d)", src, dest, weight);
    }
}