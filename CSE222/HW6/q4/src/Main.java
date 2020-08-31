public class Main {
    
    public static void main(String[] args) {
        Tester.runTests(new HashTableOpen<>());
        Tester.runTests(new HashMapChainBst<>());
        System.out.println("==END OF TESTS==");
        System.out.println();
        Benchmark.runBenchMark();
        System.out.println("==END OF BENCHMARK==");
        System.out.println();
    }

}