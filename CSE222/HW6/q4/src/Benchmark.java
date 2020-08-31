/**
 * Benchmark class for various KWHashMap structures
 * It puts 150k data into structure
 * then reads 150k data from structure
 * calculates execution time in seconds
 */
public class Benchmark {
    
    private static final double TIME = 1_000_000_000.0;

    public static void runBenchMark() {
        HashMapChainBst<Integer, Integer> chainBst =  new HashMapChainBst<>();
        HashTableOpen<Integer, Integer> doubleHashOpen = new HashTableOpen<>();
        BookHashTableChain<Integer, Integer> bookChain = new BookHashTableChain<>();
        BookHashTableOpen<Integer, Integer> bookOpen = new BookHashTableOpen<>();

        System.out.println("Benchmark my HashMap with chaining Binary Trees: ");
        System.out.println("Time: " + (bench_hashMap(chainBst) / TIME) + "s");

        System.out.println("Benchmark my HashMap with open table double hashing: ");
        System.out.println("Time: " + (bench_hashMap(doubleHashOpen) / TIME) + "s");

        System.out.println("Benchmark book HashMap with chaining linkedlists: ");
        System.out.println("Time: " + (bench_hashMap(bookChain) / TIME) + "s");

        System.out.println("Benchmark book HashMap with open table linear probing: ");
        System.out.println("Time: " + (bench_hashMap(bookOpen) / TIME) + "s");
    }

    public static long bench_hashMap(KWHashMap<Integer, Integer> map) {
        long startTime = System.nanoTime();

        for(int i = 0; i < 150_000; i++) {
            map.put(i, i+1);
        }

        for(int i = 0; i < 150_000; i++) {
            map.get(i);
        }

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

}