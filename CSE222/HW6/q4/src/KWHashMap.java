
/**
 * Interface taken from book
 * 
 * @param <K> key type
 * @param <V> value type
 */
public interface KWHashMap<K, V> {
	V get(Object key); 
	boolean isEmpty(); 
	V put(K key, V value); 
	V remove(Object key); 
	int size();

	/**
	 * I added this one for demo
	 */
	void print();
}
