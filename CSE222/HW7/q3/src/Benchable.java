
/**
 * Custom interface for benchable data structures
 * Used this for gathering different data structures under one interface
 * To make benchmarking process easier
 * 
 * @param <E> type of data inside adt
 */
public interface Benchable<E> {
    boolean add(E data);
    boolean remove(E data);
    void clear();
    String getName();
}