public class BookSorts {
    public static void selectionSort(Comparable[] table) {
        int n = table.length;
        for (int fill = 0; fill < n - 1; fill++) {
            int posMin = fill;
            for (int next = fill + 1; next < n; next++) {
                if (table[next].compareTo(table[posMin]) < 0) {
                    posMin = next;
                }
            }
            Comparable temp = table[fill];
            table[fill] = table[posMin];
            table[posMin] = temp;
        }
    }

    public static <T extends Comparable<T>> void insertionSort(T[] table) {
        for (int nextPos = 1; nextPos < table.length; nextPos++) {

            insertionInsert(table, nextPos);
        }
    }

    private static <T extends Comparable<T>> void insertionInsert(T[] table, int nextPos) {
        T nextVal = table[nextPos];

        while (nextPos > 0 && nextVal.compareTo(table[nextPos - 1]) < 0) {
            table[nextPos] = table[nextPos - 1];

            --nextPos;

        }

        table[nextPos] = nextVal;
    }

    private static <T extends Comparable<T>> void shellInsert(T[] table, int nextPos, int gap) {
        T nextVal = table[nextPos];

        while ((nextPos > gap - 1) && (nextVal.compareTo(table[nextPos - gap]) < 0)) {

            table[nextPos] = table[nextPos - gap];

            nextPos -= gap;

        }
        table[nextPos] = nextVal;

    }

    public static <T extends Comparable<T>> void shellSort(T[] table) {

        int gap = table.length / 2;
        while (gap > 0) {
            for (int nextPos = gap; nextPos < table.length; nextPos++) {

                shellInsert(table, nextPos, gap);
            }

            if (gap == 2) {
                gap = 1;
            } else {
                gap = (int) (gap / 2.2);
            }
        }
    }

    private static <T extends Comparable<T>> void merge(T[] outputSequence, T[] leftSequence, T[] rightSequence) {
        int i = 0;

        int j = 0;

        int k = 0;

        while (i < leftSequence.length && j < rightSequence.length) {

            if (leftSequence[i].compareTo(rightSequence[j]) < 0) {
                outputSequence[k++] = leftSequence[i++];
            } else {
                outputSequence[k++] = rightSequence[j++];
            }
        }

        while (i < leftSequence.length) {
            outputSequence[k++] = leftSequence[i++];
        }

        while (j < rightSequence.length) {
            outputSequence[k++] = rightSequence[j++];
        }
    }

    public static <T extends Comparable<T>> void mergeSort(T[] table) {

        if (table.length > 1) {

            int halfSize = table.length / 2;
            T[] leftTable = (T[]) new Comparable[halfSize];
            T[] rightTable = (T[]) new Comparable[table.length - halfSize];
            System.arraycopy(table, 0, leftTable, 0, halfSize);
            System.arraycopy(table, halfSize, rightTable, 0, table.length - halfSize);

            mergeSort(leftTable);
            mergeSort(rightTable);

            merge(table, leftTable, rightTable);
        }
    }

    public static <T extends Comparable<T>> void heapSort(T[] table) {
        buildHeap(table);
        shrinkHeap(table);
    }

    private static <T extends Comparable<T>> void buildHeap(T[] table) {
        int n = 1;

        while (n < table.length) {
            n++;
            int child = n - 1;
            int parent = (child - 1) / 2;
            while (parent >= 0 && table[parent].compareTo(table[child]) < 0) {
                swap(table, parent, child);
                child = parent;
                parent = (child - 1) / 2;
            }
        }
    }

    private static <T extends Comparable<T>> void shrinkHeap(T[] table) {
        int n = table.length;

        while (n > 0) {
            n--;
            swap(table, 0, n);

            int parent = 0;
            while (true) {
                int leftChild = 2 * parent + 1;
                if (leftChild >= n) {
                    break;
                }
                int rightChild = leftChild + 1;

                int maxChild = leftChild;
                if (rightChild < n && table[leftChild].compareTo(table[rightChild]) < 0) {
                    maxChild = rightChild;
                }

                if (table[parent].compareTo(table[maxChild]) < 0) {

                    swap(table, parent, maxChild);

                    parent = maxChild;
                } else {
                    break;
                }
            }
        }
    }

    private static <T extends Comparable<T>> void swap(T[] table, int i, int j) {
        T temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }

    public static <T extends Comparable<T>> void sort(T[] table) {

        quickSort(table, 0, table.length - 1);
    }

    private static <T extends Comparable<T>> void quickSort(T[] table, int first, int last) {
        if (first < last) {

            int pivIndex = partition(table, first, last);

            quickSort(table, first, pivIndex - 1);

            quickSort(table, pivIndex + 1, last);
        }
    }

    private static <T extends Comparable<T>> int partition(T[] table, int first, int last) {

        T pivot = table[first];
        int up = first;
        int down = last;
        do {
            while ((up < last) && (pivot.compareTo(table[up]) >= 0)) {
                up++;
            }

            while (pivot.compareTo(table[down]) < 0) {
                down--;
            }

            if (up < down) {

                swap(table, up, down);
            }
        } while (up < down);

        swap(table, first, down);

        return down;
    }

    public static <T extends Comparable<T>> void bubbleSort(T[] table) {
        int pass = 1;
        boolean exchanges = false;
        do {

            exchanges = false;
            for (int i = 0; i < table.length - pass; ++i) {
                if (table[i].compareTo(table[i + 1]) > 0) {

                    T temp = table[i];
                    table[i] = table[i + 1];
                    table[i + 1] = temp;
                    exchanges = true;

                }
            }
            pass++;
        } while (exchanges);

    }
}
