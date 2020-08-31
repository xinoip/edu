import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;
import java.util.Scanner;

/**
 * DijkstraMazeSolver is a MazeSolver implementation that uses Dijkstras
 * Algorithm to construct the shortest path.
 * 
 * It also uses the junctions inside the given input maze to construct the graph
 * from.
 * 
 * The graph used in this implementation is ListGraph.
 */
public class DijkstraMazeSolver extends AbstractMazeSolver {
    /**
     * Internal Graph representaion of Maze
     */
    private Graph graph;
    /**
     * Vertex list of Maze Graph
     */
    protected List<MazeVertex> vertexList;

    /**
     * Creates the DijkstraMazeSolver from the file. Calls the super constructor
     * first so check AbstractMazeSolver
     * 
     * @param file input maze file
     * @throws FileNotFoundException file not found
     */
    public DijkstraMazeSolver(File file) throws FileNotFoundException {
        super(file);
        // create empty vertexList
        vertexList = new ArrayList<>();
        // add start and end vertices
        vertexList.add(startVertex);
        vertexList.add(endVertex);
        // initialize graph
        initGraph();
    }

    @Override
    public String shortestPath() {
        int[] pred = new int[graph.getNumV()];
        double[] dist = new double[graph.getNumV()];
        dijkstrasAlgorithm(graph, 0, pred, dist);

        // for (double d : dist) {
        // System.out.println(d);
        // }

        // for (int i = 0; i < graph.getNumV(); i++) {
        // Iterator<Edge> itr = graph.edgeIterator(i);
        // while (itr.hasNext()) {
        // Edge edge = itr.next();
        // MazeVertex src = vertexList.get(edge.getSource());
        // MazeVertex dest = vertexList.get(edge.getDest());
        // double weight = edge.getWeight();

        // System.out.println(src + " -> " + dest + "{" + weight + "}");
        // }
        // System.out.println("-------");
        // }

        List<MazeVertex> pathVertexList = new ArrayList<>();

        int currPred = pred[pred.length - 1];
        while (currPred != 0) {
            MazeVertex vertex = vertexList.get(currPred);
            pathVertexList.add(vertex);
            currPred = pred[currPred];
        }

        StringBuilder sb = new StringBuilder();
        sb.append(endVertex + " -> ");
        for (MazeVertex v : pathVertexList) {
            sb.append(v + " -> ");
        }
        sb.append(startVertex);
        return sb.toString();
    }

    @Override
    public Graph getGraph() {
        return graph;
    }

    @Override
    public String allEdges() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < graph.getNumV(); i++) {
            Iterator<Edge> itr = graph.edgeIterator(i);
            while (itr.hasNext()) {
                Edge edge = itr.next();
                MazeVertex src = vertexList.get(edge.getSource());
                MazeVertex dest = vertexList.get(edge.getDest());
                double weight = edge.getWeight();

                sb.append(src + " -> " + dest + "{" + weight + "}\n");
            }
            sb.append("------\n");
        }
        return sb.toString();
    }

    /**
     * Helper method for initializing graphs
     */
    private void initGraph() {
        // get the MazeEdge list by traversing the tree
        List<MazeEdge> edgeList = traverse();
        // get the correct string input for AbstractGraphs loadFromFileMethod
        String srcString = scanString(edgeList);
        // scanner for that string input
        Scanner scan = new Scanner(srcString);
        // create the graph by using AbstractGraphs creation
        graph = AbstractGraph.createGraph(scan, false, "list");
        scan.close();
    }

    /**
     * Constructs and returns the correct input string for
     * AbstractGraph.createGraph(...) from List<MazeEdge> which is my custom
     * implementation for representing maze connections.
     * 
     * Because of the idiotic way of books adt implementation is forcing me to
     * encode these coordinates into single integers from 0 to N, thıs method does
     * that.
     * 
     * It does the encoding by tracking the internal VertexLists index values. So if
     * the VertexList[0] is (3,5), coordinate wise, it is still encoded to 0 to be
     * appropriate for books implementation.
     * 
     * @param edgeList connections inside maze, represented as List<MazeEdge>
     * @return correct input for AbstractGraph creation method
     */
    private String scanString(List<MazeEdge> edgeList) {
        StringBuilder sb = new StringBuilder();
        int numV = vertexList.size();
        vertexList.remove(1);
        vertexList.add(endVertex);
        sb.append(numV);
        sb.append("\n");
        for (MazeEdge e : edgeList) {
            // get the encoded value for books adt
            int srcId = vertexList.indexOf(e.getSrc());
            int destId = vertexList.indexOf(e.getDest());

            // construct the line: {src} {dest} {weight}
            sb.append(srcId);
            sb.append(" ");
            sb.append(destId);
            sb.append(" ");
            sb.append(e.getWeight());
            sb.append("\n");
        }

        return sb.toString();
    }

    /**
     * Traverses the 2d maze array and constructs the every edge. It only constructs
     * the edges from junction to junction.
     * 
     * @return list of MazeEdges
     */
    private List<MazeEdge> traverse() {
        // current edge list
        List<MazeEdge> edgeList = new ArrayList<>();
        // next to traverse from
        Stack<MazeVertex> stack = new Stack<>();
        // current vertex
        MazeVertex vertex = startVertex;
        // visited list for preventing loops
        List<MazeVertex> visited = new ArrayList<>();

        // start from current
        stack.push(vertex);
        while (!stack.empty()) {
            vertex = stack.pop();

            // if already visited, continue
            if (visited.contains(vertex)) {
                continue;
            }

            // get left,top,right,bottom vertices from current vertex
            List<MazeVertex> ltrb = ltrbVertices(vertex);
            MazeVertex left = ltrb.get(0);
            MazeVertex top = ltrb.get(1);
            MazeVertex right = ltrb.get(2);
            MazeVertex bottom = ltrb.get(3);
            int weight = 1;

            // go left until it is not valid or a junction is encountered, calculate weight
            // while going
            while (left.isEmpty() && isValidVertex(left) && !isJunctionVertex(left)) {
                left.goLeft();
                weight++;
            }
            // if while is breaked because of junction
            if (isJunctionVertex(left)) {
                // create the edge from current vertex to left
                MazeEdge edge = new MazeEdge(vertex, left, weight);
                // if we already added it symettric dont add it
                // else add the edge
                if (!edgeList.contains(edge.symetric())) {
                    edgeList.add(edge);
                }
                // if already added the verices dont add the vertices to vertex list
                // else add the vertex
                if (!vertexList.contains(vertex)) {
                    vertexList.add(vertex);
                }
                if (!vertexList.contains(left)) {
                    vertexList.add(left);
                }
                // Next loop, start from left
                stack.add(left);
            }
            weight = 1;

            // same procedure for going top...
            while (top.isEmpty() && isValidVertex(top) && !isJunctionVertex(top)) {
                top.goTop();
                weight++;
            }
            if (isJunctionVertex(top)) {
                MazeEdge edge = new MazeEdge(vertex, top, weight);
                if (!edgeList.contains(edge.symetric())) {
                    edgeList.add(edge);
                }
                if (!vertexList.contains(vertex)) {
                    vertexList.add(vertex);
                }
                if (!vertexList.contains(top)) {
                    vertexList.add(top);
                }
                stack.add(top);
            }
            weight = 1;

            // same procedure for going right...
            while (right.isEmpty() && isValidVertex(right) && !isJunctionVertex(right)) {
                right.goRight();
                weight++;
            }
            if (isJunctionVertex(right)) {
                MazeEdge edge = new MazeEdge(vertex, right, weight);
                if (!edgeList.contains(edge.symetric())) {
                    edgeList.add(edge);
                }
                if (!vertexList.contains(vertex)) {
                    vertexList.add(vertex);
                }
                if (!vertexList.contains(right)) {
                    vertexList.add(right);
                }
                stack.add(right);
            }
            weight = 1;

            // same procedure for going bottom...
            while (bottom.isEmpty() && isValidVertex(bottom) && !isJunctionVertex(bottom)) {
                bottom.goBottom();
                weight++;
            }
            if (isJunctionVertex(bottom)) {
                MazeEdge edge = new MazeEdge(vertex, bottom, weight);
                if (!edgeList.contains(edge.symetric())) {
                    edgeList.add(edge);
                }
                if (!vertexList.contains(vertex)) {
                    vertexList.add(vertex);
                }
                if (!vertexList.contains(bottom)) {
                    vertexList.add(bottom);
                }
                stack.add(bottom);
            }
            weight = 1;

            // done visiting the current vertice
            visited.add(vertex);
        }

        // return the aggregated edges
        return edgeList;
    }

    /**
     * DijkstrasAlgorithm method, taken from book
     * 
     * Takes a graph, and a start point, outputs pred and dist arrays.
     * 
     * @param graph input graph
     * @param start input vertex
     * @param pred  predecessors of start
     * @param dist  distances to indexes
     */
    public static void dijkstrasAlgorithm(Graph graph, int start, int[] pred, double[] dist) {
        int numV = graph.getNumV();
        HashSet<Integer> vMinusS = new HashSet<>(numV);
        // Initialize V–S.
        for (int i = 0; i < numV; i++) {
            if (i != start) {
                vMinusS.add(i);
            }
        }
        // Initialize pred and dist.
        for (int v : vMinusS) {
            pred[v] = start;
            if (graph.getEdge(start, v) != null) {
                dist[v] = graph.getEdge(start, v).getWeight();
            } else {
                dist[v] = Integer.MAX_VALUE;
            }
        }
        // Main loop
        while (vMinusS.size() != 0) {
            // Find the value u in V–S with the smallest dist[u].
            double minDist = Double.POSITIVE_INFINITY;
            int u = -1;
            for (int v : vMinusS) {
                if (dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
            // Remove u from vMinusS.
            vMinusS.remove(u);
            // Update the distances.
            Iterator<Edge> edgeIter = graph.edgeIterator(u);
            while (edgeIter.hasNext()) {
                Edge edge = edgeIter.next();
                int v = edge.getDest();
                if (vMinusS.contains(new Integer(v))) {
                    double weight = edge.getWeight();
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pred[v] = u;
                    }
                }
            }
        }
    }

}