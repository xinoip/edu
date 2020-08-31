import java.util.LinkedList;
import java.util.List;

public class LLSorts {
    public static <T extends Comparable<T>> void quickSort(List<T> table) {

        quickSortHelper(table, 0, table.size() - 1);
    }

    private static <T extends Comparable<T>> void quickSortHelper(List<T> table, int first, int last) {
        if (first < last) {

            int pivIndex = partition(table, first, last);

            quickSortHelper(table, first, pivIndex - 1);

            quickSortHelper(table, pivIndex + 1, last);
        }
    }

    private static <T extends Comparable<T>> int partition(List<T> table, int first, int last) {

        T pivot = table.get(first);
        int up = first;
        int down = last;
        do {
            while ((up < last) && (pivot.compareTo(table.get(up)) >= 0)) {
                up++;
            }

            while (pivot.compareTo(table.get(down)) < 0) {
                down--;
            }

            if (up < down) {

                swap(table, up, down);
            }
        } while (up < down);

        swap(table, first, down);

        return down;
    }

    private static <T extends Comparable<T>> void merge(List<T> outputSequence, List<T> leftSequence,
            List<T> rightSequence) {
        int i = 0;

        int j = 0;

        int k = 0;

        while (i < leftSequence.size() && j < rightSequence.size()) {

            if (leftSequence.get(i).compareTo(rightSequence.get(j)) < 0) {
                outputSequence.set(k, leftSequence.get(i));
                k++;
                i++;
            } else {
                outputSequence.set(k, rightSequence.get(j));
                k++;
                j++;
            }
        }

        while (i < leftSequence.size()) {
            outputSequence.set(k, leftSequence.get(i));
            k++;
            i++;
        }

        while (j < rightSequence.size()) {
            outputSequence.set(k, rightSequence.get(j));
            k++;
            j++;
        }
    }

    public static <T extends Comparable<T>> void mergeSort(List<T> table) {

        if (table.size() > 1) {

            int halfSize = table.size() / 2;
            List<T> leftTable = new LinkedList<>();
            List<T> rightTable = new LinkedList<>();
            leftTable.addAll(table.subList(0, halfSize));
            rightTable.addAll(table.subList(halfSize, table.size()));

            mergeSort(leftTable);
            mergeSort(rightTable);

            merge(table, leftTable, rightTable);
        }
    }

    private static <T extends Comparable<T>> void swap(List<T> table, int i, int j) {
        T temp = table.get(i);
        table.set(i, table.get(j));
        table.set(j, temp);
    }
}