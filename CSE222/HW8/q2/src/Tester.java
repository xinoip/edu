public class Tester {
    
    private static DoubleLinkedGraph graph = new DoubleLinkedGraph(10, true);

    public static void runTests() {
        t_insertTest();
        t_isEdgeTest();
        t_getEdgeTest();
        t_addVertex();
        t_addEdgeToNewVertex();
        t_isEdgeTest();
    }

    private static void t_insertTest() {
        System.out.println("Inserting 0,4 - 0,2 - 1,2 edges");
        graph.insert(new Edge(0, 4));
        graph.insert(new Edge(0, 2));
        graph.insert(new Edge(1, 2));
    }

    private static void t_isEdgeTest() {
        System.out.println("isEdge 0,4 - 0,2 - 1,2 - 5,0 edges");
        System.out.println("isEdge 0,4:" + graph.isEdge(0, 4));
        System.out.println("isEdge 0,2:" + graph.isEdge(0, 2));
        System.out.println("isEdge 1,2:" + graph.isEdge(1, 2));
        System.out.println("isEdge 5,0:" + graph.isEdge(5, 0));
        System.out.println("isEdge 5,14:" + graph.isEdge(5, 14));
    }

    private static void t_getEdgeTest() {
        Edge edge = graph.getEdge(0, 4);
        System.out.println("Got the edge (0,4): " + edge);
    }

    private static void t_addVertex() {
        graph.insertVertex(14);
        System.out.println("Added new vertex: 14");
    }

    private static void t_addEdgeToNewVertex() {
        graph.insert(new Edge(5, 14));
        System.out.println("Added new edge to new vertex: 5,14");
    }

}