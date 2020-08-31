import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * Concrete implementation of AbstractExtendedGraph
 * 
 * I couldn't finish the extra methods, did not had the time. It only provided
 * functionality of inserting and reading edges and vertices, no deletion. Sorry
 * about that.
 */
public class DoubleLinkedGraph extends AbstractExtendedGraph {
    /**
     * Internal structure of graph, row linkedlist
     */
    private List<Node> rowList;
    /**
     * Internal structure of graph, col linkedlist
     */
    private List<Node> colList;

    public DoubleLinkedGraph(int numV, boolean directed) {
        super(numV, directed);
        this.rowList = new LinkedList<>();
        this.colList = new LinkedList<>();

        for (int i = 0; i < numV; i++) {
            rowList.add(new Node(new Edge(i, i)));
            colList.add(new Node(new Edge(i, i)));
        }
    }

    /**
     * Basic tuple struct for method positionFinder
     */
    private class Position {
        public int row;
        public int col;

        public Position(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    /**
     * Finds the given position heads from linkedlists
     * 
     * @param src  row list head
     * @param dest col list head
     * @return positions inside a tuple
     */
    private Position positionFinder(int src, int dest) {
        int rowIndex = -1;
        for (int i = 0; i < rowList.size(); i++) {
            Node rowNode = rowList.get(i);
            if (rowNode.edge.getSource() == src) {
                rowIndex = i;
                break;
            }
        }

        int colIndex = -1;
        for (int i = 0; i < colList.size(); i++) {
            Node colNode = colList.get(i);
            if (colNode.edge.getSource() == dest) {
                colIndex = i;
                break;
            }
        }

        return new Position(rowIndex, colIndex);
    }

    @Override
    public void insert(Edge edge) {
        Node node = new Node(edge);

        int rowIndex = -1;
        int colIndex = -1;
        Position pos = positionFinder(edge.getSource(), edge.getDest());
        rowIndex = pos.row;
        colIndex = pos.col;
        if (rowIndex == -1 || colIndex == -1) {
            return;
        }

        Node rowHead = rowList.get(rowIndex);
        Node colHead = colList.get(colIndex);

        Node current = rowHead;
        while (node.edge.getSource() > current.edge.getSource()) {
            current = current.rnext;
        }
        current.rprev = node;
        node.rnext = current;

        current = colHead;
        while (node.edge.getDest() > current.edge.getDest()) {
            current = current.cnext;
        }
        current.cprev = node;
        node.cnext = current;
    }

    @Override
    public boolean isEdge(int source, int dest) {
        return getEdge(source, dest) != null;
    }

    @Override
    public Edge getEdge(int source, int dest) {
        int rowIndex = -1;
        int colIndex = -1;
        Position pos = positionFinder(source, dest);
        rowIndex = pos.row;
        colIndex = pos.col;
        if (rowIndex == -1 || colIndex == -1) {
            return null;
        }

        Node rowHead = rowList.get(rowIndex);
        Node colHead = colList.get(colIndex);

        Node current = rowHead;
        while (source > current.edge.getSource()) {
            current = current.rnext;
        }
        if (current == null || current.rprev == null)
            return null;
        if (current.rprev.edge.getSource() != source)
            return null;

        current = colHead;
        while (dest > current.edge.getDest()) {
            current = current.cnext;
        }
        if (current == null || current.cprev == null)
            return null;
        if (current.cprev.edge.getDest() != dest)
            return null;

        return current.edge;
    }

    @Override
    public Iterator<Edge> edgeIterator(int source) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public boolean deleteEdge(Edge edge) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void insertVertex(int vertex) {
        rowList.add(new Node(new Edge(vertex, vertex)));
        colList.add(new Node(new Edge(vertex, vertex)));
    }

    @Override
    public void deleteVertex(int vertex) {
        // TODO Auto-generated method stub

    }

    @Override
    public void bfs() {
        // TODO Auto-generated method stub

    }

    @Override
    public void dfs() {
        // TODO Auto-generated method stub

    }

    /**
     * Class representing a node inside 2D Linked structure
     */
    private class Node {
        /**
         * Row successor
         */
        public Node rnext;
        /**
         * Row predeccor
         */
        public Node rprev;
        /**
         * Row successor
         */
        public Node cnext;
        /**
         * Col predeccor
         */
        public Node cprev;
        /**
         * Containing data is an edge
         */
        public Edge edge;

        /**
         * Creates a Node from edge
         * 
         * @param edge nodes containing edge
         */
        public Node(Edge edge) {
            this.edge = edge;
        }

        @Override
        public String toString() {
            return String.format("Node[edge=%s, rnext=%s, rprev=%s, cnext=%s, cprev=%s]", edge, rnext, rprev, cnext,
                    cprev);
        }
    }
}