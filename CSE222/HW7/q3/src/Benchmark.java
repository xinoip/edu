import java.util.AbstractSet;
import java.util.TreeSet;
import java.util.concurrent.ConcurrentSkipListSet;

public class Benchmark {

    private static final double TIME = 1_000_000_000.0;

    public static void runBenchmarks() {
        // BST
        testGeneric(new BinarySearchTree<>());

        // RedBlack Tree Book
        testGeneric(new RedBlackTree<>());

        // B-Tree Book
        // testGeneric(new BTree<>(5));        

        // RedBlack Tree Java
        testGenericJavaVersions(new TreeSet<>());

        // SkipList Book
        testGeneric(new SkipList<>());

        // SkipList Java
        testGenericJavaVersions(new ConcurrentSkipListSet<>());
    }

    /**
     * Generic bench method for benching adts that implements Benchable interface
     * Benchable interface is my custom interface to gather all this adts under one interface
     * 
     * The bench starts with current size of 10k then goes in order 20k, 40k, 80k
     * It generates 10 of each adt with random data of each current size
     * 
     * After generation, it randomly adds 10 more and calculates running time for that operation
     * 
     * Then it deletes those 10 values and calculates running time for this operation as well
     * 
     * @param adt Benchable Abstract Data Type
     */
    private static void testGeneric(Benchable<Integer> adt) {
        System.out.println("------");
        int currentSize = 10_000;
        while (currentSize <= 80_000) {
            for (int i = 0; i < 10; i++) {
                System.out.println(i + " Benchmarking: " + adt.getName() + " with size of " + currentSize);
                adt.clear();
                Integer[] arr = Generator.generateArr(currentSize, false);
                for (Integer element : arr) {
                    adt.add(element);
                }
                
                Integer[] randomTen = Generator.generateArr(10, false);
                System.out.println("Adding 10 random items..");
                long startTime = System.nanoTime();
                for (Integer element : randomTen) {
                    adt.add(element);
                }
                long stopTime = System.nanoTime();
                System.out.println((stopTime - startTime) / TIME);

                System.out.println("Deleting those 10 items..");
                startTime = System.nanoTime();
                for (Integer element : randomTen) {
                    adt.remove(element);
                }
                stopTime = System.nanoTime();
                System.out.println((stopTime - startTime) / TIME);
            }

            currentSize *= 2;
        }
        System.out.println("------");
    }

    /**
     * Same benchmark for java versions of adts
     * Since i cant gather these java versions under my custom interface
     * I used this AbstractSet to gather them genericly
     * 
     * @param adt java implementation of AbstractSet
     */
    private static void testGenericJavaVersions(AbstractSet<Integer> adt) {
        System.out.println("------");
        int currentSize = 10_000;
        while (currentSize <= 80_000) {
            for (int i = 0; i < 10; i++) {
                System.out.println(i + " Benchmarking: " + adt.getClass().getName() + " with size of " + currentSize);
                System.out.println("index: " + i + " with size of " + currentSize);
                adt.clear();
                Integer[] arr = Generator.generateArr(currentSize, false);
                for (Integer element : arr) {
                    adt.add(element);
                }
                
                Integer[] randomTen = Generator.generateArr(10, false);
                System.out.println("Adding 10 random items..");
                long startTime = System.nanoTime();
                for (Integer element : randomTen) {
                    adt.add(element);
                }
                long stopTime = System.nanoTime();
                System.out.println((stopTime - startTime) / TIME);

                System.out.println("Deleting those 10 items..");
                startTime = System.nanoTime();
                for (Integer element : randomTen) {
                    adt.remove(element);
                }
                stopTime = System.nanoTime();
                System.out.println((stopTime - startTime) / TIME);
            }

            currentSize *= 2;
        }
        System.out.println("------");
    }

}