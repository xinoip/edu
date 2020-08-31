import java.io.File;
import java.io.FileNotFoundException;

public class Main {

    private static final String FILE_NAME = "./maze.txt";

    public static void main(String[] args) {
        File file = new File(FILE_NAME);
        try {
            MazeSolver mazeSolver = new DijkstraMazeSolver(file);
            String shortestPath = mazeSolver.shortestPath();
            System.out.println("All edges: " + mazeSolver.allEdges());
            System.out.println("Shortest path: " + shortestPath);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

}