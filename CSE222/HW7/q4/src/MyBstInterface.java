
/**
 * Basic SearchTree interface, which is also iterable
 * 
 * Iterable only used for demo purposes, showing the whole tree is correct.
 * 
 * @param <T> data type
 */
public interface MyBstInterface<T> extends Iterable<T> {
    int size();
    boolean isEmpty();
    void put(T value);
    T remove(T value);
    T search(T value);
}