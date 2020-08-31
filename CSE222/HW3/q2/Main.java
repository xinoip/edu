import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {

    private static PrintWriter writer;

    public static void main(String[] args) {

        try {
            writer = new PrintWriter("./logfile.txt");
        } catch (Exception e) {
            System.err.println("IO Exception occurred!");
        }

        SimpleTextEditor editorAL = new SimpleTextEditor(new ArrayList<Character>());
        SimpleTextEditor editorLL = new SimpleTextEditor(new LinkedList<Character>());

        testRead(editorAL, "ArrayList");
        writer.println();
        testRead(editorLL, "LinkedList");

        writer.println();

        testAdd(editorAL, "ArrayList");
        writer.println();
        testAdd(editorLL, "LinkedList");
        writer.println();
        testFind(editorAL, "ArrayList");
        writer.println();
        testFind(editorLL, "LinkedList");
        writer.println();
        testReplace(editorAL, "ArrayList");
        writer.println();
        testReplace(editorLL, "LinkedList");

        writer.close();

	System.out.println("TESTS DONE: Check the log file ./logfile.txt");
    }

    public static void testRead(SimpleTextEditor editor, String type) {
        writer.println("Test: read from file with " + type);

        writer.println("Reading with loop implementation");
        long start = System.nanoTime();
        editor.readLoop("filetoread");
        long end = System.nanoTime();
        long time = end - start;
        double timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Elapsed time: " + timeInSecond);

        start = System.nanoTime();
        writer.println("Reading with iterator implementation");
        editor.readIter("filetoread");
        end = System.nanoTime();
        time = end - start;
        timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Elapsed time: " + timeInSecond);
    }

    public static void testAdd(SimpleTextEditor editor, String type) {
        writer.println("Test: add string to index 5 with " + type);

        writer.println("Adding string with loop implementation");
        long start = System.nanoTime();
        editor.addLoop(5, "INSERTED");
        long end = System.nanoTime();
        long time = end - start;
        double timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Elapsed time: " + timeInSecond);

        start = System.nanoTime();
        writer.println("Adding string with iterator implementation");
        editor.addIter(5, "INSERTED");
        end = System.nanoTime();
        time = end - start;
        timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Elapsed time: " + timeInSecond);
    }

    public static void testFind(SimpleTextEditor editor, String type) {
        writer.println("Test: find string INSERTED with " + type);

        writer.println("Finding string with loop implementation");
        long start = System.nanoTime();
        int index = editor.findLoop("INSERTED");
        index++;
        long end = System.nanoTime();
        long time = end - start;
        double timeInSecond = (double) time / 1000000;
        writer.println("Found at index: " + index);
        writer.println("Elapsed time: " + timeInSecond);

        start = System.nanoTime();
        writer.println("Finding string with iterator implementation");
        index = editor.findIter("INSERTED");
        end = System.nanoTime();
        time = end - start;
        timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Found at index: " + index);
        writer.println("Elapsed time: " + timeInSecond);
    }

    public static void testReplace(SimpleTextEditor editor, String type) {
        writer.println("Test: replace all character e with character * with " + type);

        writer.println("Replacing with loop implementation");
        long start = System.nanoTime();
        editor.replaceLoop('e', '*');
        long end = System.nanoTime();
        long time = end - start;
        double timeInSecond = (double) time / 1000000;
        writer.println("Elapsed time: " + timeInSecond);

        start = System.nanoTime();
        writer.println("Replacing with iterator implementation");
        editor.replaceIter('e', '*');
        end = System.nanoTime();
        time = end - start;
        timeInSecond = (double) time / 1000000;
        writer.println(editor.toString());
        writer.println("Elapsed time: " + timeInSecond);
    }
}
