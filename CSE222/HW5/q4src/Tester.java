
/**
 * Tests for MaxHeap
 */
public class Tester {

    public static void print(String str) {
        System.out.println(str);
    }

    public static void startTests() {
        t_addData();
        print("");
        t_removeData();
        print("");
        t_olderYoungerThan();
        print("");
        t_find();
    }

    private static void t_addData() {
        print("Adding data to heap to demonstrate add and tostring functions: ");
        MaxHeap<AgeData> heap = new MaxHeap<AgeData>();
        heap.add(new AgeData(10));
        heap.add(new AgeData(5));
        heap.add(new AgeData(70));
        heap.add(new AgeData(10));
        heap.add(new AgeData(50));
        heap.add(new AgeData(5));
        heap.add(new AgeData(15));
        print(heap.toString());
    }

    private static void t_removeData() {
        print("Removing data from heap: ");
        MaxHeap<AgeData> heap = new MaxHeap<AgeData>();
        heap.add(new AgeData(10));
        heap.add(new AgeData(5));
        heap.add(new AgeData(70));
        heap.add(new AgeData(10));
        heap.add(new AgeData(50));
        heap.add(new AgeData(5));
        heap.add(new AgeData(15));
        print("Initial heap: ");
        print(heap.toString());
        print("Removing AgeData(10): ");
        heap.remove(new AgeData(10));
        print(heap.toString());
        print("Removing AgeData(50): ");
        heap.remove(new AgeData(50));
        print(heap.toString());
    }

    private static void t_olderYoungerThan() {
        print("Removing data from heap: ");
        MaxHeap<AgeData> heap = new MaxHeap<AgeData>();
        heap.add(new AgeData(10));
        heap.add(new AgeData(5));
        heap.add(new AgeData(70));
        heap.add(new AgeData(10));
        heap.add(new AgeData(50));
        heap.add(new AgeData(5));
        heap.add(new AgeData(15));
        print("Initial heap: ");
        print(heap.toString());
        print("olderThan(5): " + heap.olderThan(5));
        print("olderThan(10): " + heap.olderThan(10));
        print("olderThan(50): " + heap.olderThan(50));
        print("youngerThan(5): " + heap.youngerThan(5));
        print("youngerThan(10): " + heap.youngerThan(10));
        print("youngerThan(50): " + heap.youngerThan(50));
        print("youngerThan(1000): " + heap.youngerThan(1000));
        print("olderThan(0): " + heap.olderThan(0));
    }

    private static void t_find() {
        print("Finding data: ");
        MaxHeap<AgeData> heap = new MaxHeap<AgeData>();
        heap.add(new AgeData(10));
        heap.add(new AgeData(5));
        heap.add(new AgeData(70));
        heap.add(new AgeData(10));
        heap.add(new AgeData(50));
        heap.add(new AgeData(5));
        heap.add(new AgeData(15));
        print("Initial heap: ");
        print(heap.toString());
        print("find(AgeData(15)): " + heap.find(new AgeData(15)));
    }
}