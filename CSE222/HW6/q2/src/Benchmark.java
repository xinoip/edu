import java.util.LinkedList;

public class Benchmark {

    public static long arr_selectionSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.selectionSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_bubbleSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.bubbleSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_insertionSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.insertionSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_shellSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.shellSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_mergeSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.mergeSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_heapSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.heapSort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long arr_quickSort(int size, boolean isSorted) {
        Integer[] arr = Generator.generateArr(size, isSorted);
        long startTime = System.nanoTime();

        BookSorts.sort(arr);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long ll_quickSort(int size, boolean isSorted) {
        LinkedList<Integer> list = Generator.generateLL(size, isSorted);
        long startTime = System.nanoTime();

        LLSorts.quickSort(list);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

    public static long ll_mergeSort(int size, boolean isSorted) {
        LinkedList<Integer> list = Generator.generateLL(size, isSorted);
        long startTime = System.nanoTime();

        LLSorts.mergeSort(list);

        long stopTime = System.nanoTime();
        return stopTime - startTime;
    }

}