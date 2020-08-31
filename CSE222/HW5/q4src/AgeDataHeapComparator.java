import java.util.Comparator;

/**
 * Custom comparator for AgeData heap
 * It compares by counts of AgeData
 * 
 * @param <E> AgeData
 */
public class AgeDataHeapComparator<E extends AgeData> implements Comparator<E> {
    @Override
    public int compare(E o1, E o2) {
        return o1.getCount() - o2.getCount();
    }
}