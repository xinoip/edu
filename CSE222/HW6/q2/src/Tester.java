import java.util.ArrayList;

public class Tester {
    public enum SortType {
        Arr_Selection, Arr_Bubble, Arr_Insertion, Arr_Shell, Arr_Merge, Arr_Heap, Arr_Quick, LL_Quick, LL_Merge
    };

    private static final double TIME = 1_000_000_000.0;

    public static void runTests() {
        // genericTest(10_000, 20, false, SortType.Arr_Selection);
        // genericTest(40_000, 20, false, SortType.Arr_Selection);
        // genericTest(100_000, 20, false, SortType.Arr_Selection);
        // genericTest(150_000, 20, false, SortType.Arr_Selection);
        // genericTest(180_000, 20, false, SortType.Arr_Selection);

        // genericTest(10_000, 20, false, SortType.Arr_Bubble);
        // genericTest(40_000, 20, false, SortType.Arr_Bubble);
        // genericTest(100_000, 20, false, SortType.Arr_Bubble);
        // genericTest(150_000, 20, false, SortType.Arr_Bubble);
        // genericTest(180_000, 20, false, SortType.Arr_Bubble);

        // genericTest(10_000, 20, false, SortType.Arr_Insertion);
        // genericTest(40_000, 20, false, SortType.Arr_Insertion);
        // genericTest(100_000, 20, false, SortType.Arr_Insertion);
        // genericTest(150_000, 20, false, SortType.Arr_Insertion);
        // genericTest(180_000, 20, false, SortType.Arr_Insertion);

        // genericTest(10_000, 20, false, SortType.Arr_Shell);
        // genericTest(40_000, 20, false, SortType.Arr_Shell);
        // genericTest(100_000, 20, false, SortType.Arr_Shell);
        // genericTest(150_000, 20, false, SortType.Arr_Shell);
        // genericTest(180_0000, 20, false, SortType.Arr_Shell);

        // genericTest(10_000, 20, false, SortType.Arr_Merge);
        // genericTest(40_000, 20, false, SortType.Arr_Merge);
        // genericTest(100_000, 20, false, SortType.Arr_Merge);
        // genericTest(150_000, 20, false, SortType.Arr_Merge);
        // genericTest(180_000, 20, false, SortType.Arr_Merge);

        // genericTest(10_000, 20, false, SortType.Arr_Heap);
        // genericTest(40_000, 20, false, SortType.Arr_Heap);
        // genericTest(100_000, 20, false, SortType.Arr_Heap);
        // genericTest(150_000, 20, false, SortType.Arr_Heap);
        // genericTest(180_000, 20, false, SortType.Arr_Heap);

        // genericTest(10_000, 20, false, SortType.Arr_Quick);
        // genericTest(40_000, 20, false, SortType.Arr_Quick);
        // genericTest(100_000, 20, false, SortType.Arr_Quick);
        // genericTest(150_000, 20, false, SortType.Arr_Quick);
        // genericTest(180_000, 20, false, SortType.Arr_Quick);

        // genericTest(10_000, 20, false, SortType.LL_Merge);
        // genericTest(40_000, 20, false, SortType.LL_Merge);
        // genericTest(100_000, 20, false, SortType.LL_Merge);
        // genericTest(150_000, 20, false, SortType.LL_Merge);
        // genericTest(180_000, 20, false, SortType.LL_Merge);

        // genericTest(10_000, 20, false, SortType.LL_Quick);
        // genericTest(40_000, 20, false, SortType.LL_Quick);
        // genericTest(100_000, 20, false, SortType.LL_Quick);
        // genericTest(150_000, 20, false, SortType.LL_Quick);
        // genericTest(180_000, 20, false, SortType.LL_Quick);

        genericTest(10_000, 1, true, SortType.Arr_Selection);
        genericTest(40_000, 1, true, SortType.Arr_Selection);
        genericTest(100_000, 1, true, SortType.Arr_Selection);
        genericTest(150_000, 1, true, SortType.Arr_Selection);
        genericTest(180_000, 1, true, SortType.Arr_Selection);

        genericTest(10_000, 1, true, SortType.Arr_Bubble);
        genericTest(40_000, 1, true, SortType.Arr_Bubble);
        genericTest(100_000, 1, true, SortType.Arr_Bubble);
        genericTest(150_000, 1, true, SortType.Arr_Bubble);
        genericTest(180_000, 1, true, SortType.Arr_Bubble);

        genericTest(10_000, 1, true, SortType.Arr_Insertion);
        genericTest(40_000, 1, true, SortType.Arr_Insertion);
        genericTest(100_000, 1, true, SortType.Arr_Insertion);
        genericTest(150_000, 1, true, SortType.Arr_Insertion);
        genericTest(180_000, 1, true, SortType.Arr_Insertion);

        genericTest(10_000, 1, true, SortType.Arr_Shell);
        genericTest(40_000, 1, true, SortType.Arr_Shell);
        genericTest(100_000, 1, true, SortType.Arr_Shell);
        genericTest(150_000, 1, true, SortType.Arr_Shell);
        genericTest(180_0000, 1, true, SortType.Arr_Shell);

        genericTest(10_000, 1, true, SortType.Arr_Merge);
        genericTest(40_000, 1, true, SortType.Arr_Merge);
        genericTest(100_000, 1, true, SortType.Arr_Merge);
        genericTest(150_000, 1, true, SortType.Arr_Merge);
        genericTest(180_000, 1, true, SortType.Arr_Merge);

        genericTest(10_000, 1, true, SortType.Arr_Heap);
        genericTest(40_000, 1, true, SortType.Arr_Heap);
        genericTest(100_000, 1, true, SortType.Arr_Heap);
        genericTest(150_000, 1, true, SortType.Arr_Heap);
        genericTest(180_000, 1, true, SortType.Arr_Heap);

        // genericTest(10_000, 1, true, SortType.Arr_Quick);
        // genericTest(40_000, 1, true, SortType.Arr_Quick);
        // genericTest(100_000, 1, true, SortType.Arr_Quick);
        // genericTest(150_000, 1, true, SortType.Arr_Quick);
        // genericTest(180_000, 1, true, SortType.Arr_Quick);

        genericTest(10_000, 1, true, SortType.LL_Merge);
        genericTest(40_000, 1, true, SortType.LL_Merge);
        genericTest(100_000, 1, true, SortType.LL_Merge);
        genericTest(150_000, 1, true, SortType.LL_Merge);
        genericTest(180_000, 1, true, SortType.LL_Merge);

        genericTest(10_000, 1, true, SortType.LL_Quick);
        genericTest(40_000, 1, true, SortType.LL_Quick);
        genericTest(100_000, 1, true, SortType.LL_Quick);
        genericTest(150_000, 1, true, SortType.LL_Quick);
        genericTest(180_000, 1, true, SortType.LL_Quick);
    }

    private static void genericTest(int size, int count, boolean isSorted, SortType sort) {
        ArrayList<Double> list = new ArrayList<>();
        String sortedInfo = "";
        if(isSorted) {
            sortedInfo = " (pre-Sorted) ";
        }
        switch (sort) {
            case Arr_Bubble:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_bubbleSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Bubble Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case Arr_Heap:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_heapSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Heap Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case Arr_Insertion:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_insertionSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Insertion Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case Arr_Merge:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_mergeSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Merge Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case Arr_Quick:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_quickSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Quick Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case Arr_Selection:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_selectionSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Selection Sort " + count + " arrays of size " + size + sortedInfo +  ": ");
                System.out.println(list);
                break;
            case Arr_Shell:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.arr_shellSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Shell Sort " + count + " arrays of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case LL_Merge:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.ll_mergeSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Merge Sort " + count + " linkedlists of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            case LL_Quick:
                for (int i = 0; i < count; i++) {
                    long result = Benchmark.ll_quickSort(size, isSorted);
                    list.add((double) result / TIME);
                }
                System.out.println("Quick Sort " + count + " linkedlists of size " + size + sortedInfo + ": ");
                System.out.println(list);
                break;
            default:
                System.out.println("Should not be here?");
                break;
        }
    }

}