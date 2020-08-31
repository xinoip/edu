/**
 * Custom hash map implementation with chaining iterable Binary Search Trees
 * 
 * @param <K> key type, should be comparable
 * @param <V> value type
 */
public class HashMapChainBst<K extends Comparable<K>, V> implements KWHashMap<K, V> {
    /**
     * Table is just array of BSTs
     */
    private MyBst<Entry>[] table;
    /**
     * Size of map
     */
    private int size;
    /**
     * Capacity
     */
    private static final int CAPACITY = 101;
    /**
     * Load threshhold for rehashing
     */
    private static final double LOAD_THRESHOLD = 3.0;

    /**
     * Default constructore, initializes empty map
     */
    HashMapChainBst() {
        table = new MyBst[CAPACITY];
        size = 0;
    }

    /**
     * MyHash function takes the keys hashcode and divs it with array length
     * 
     * @param key key to take hashcode from
     * @return hash
     */
    private int myHash(Object key) {
        int hash = key.hashCode() % table.length;
        if (hash < 0)
            hash += table.length;
        return hash;
    }

    /**
     * Rehash implementation
     */
    private void rehash() {
        MyBst<Entry>[] oldTable = table;

        table = new MyBst[2 * oldTable.length + 1];

        size = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if (oldTable[i] != null) {
                for (Entry item : oldTable[i]) {
                    put(item.key, item.value);
                }
            }
        }
    }

    /**
     * Entry class is for entries of map, it is comparable
     */
    private class Entry implements Comparable<Entry> {
        /**
         * The key of entry
         */
        private K key;
        /**
         * The value of entry
         */
        private V value;

        /**
         * Default constructor takes key and value for entry
         * 
         * @param key key of new entry
         * @param value value of new entry
         */
        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        /**
         * Returns Entry(key, value)
         */
        @Override
        public String toString() {
            return String.format("Entry(%s, %s)", key, value);
        }

        /**
         * Compares keys of entries
         */
        @Override
        public int compareTo(Entry o) {
            return key.compareTo(o.key);
        }
    }

    @Override
    public V get(Object key) {
        int hash = myHash(key);

        if (table[hash] == null)
            return null;

        for (Entry nextItem : table[hash]) {
            if (nextItem.key.equals(key))
                return nextItem.value;
        }

        return null;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public V put(K key, V value) {
        int hash = myHash(key);

        if (table[hash] == null)
            table[hash] = new MyBst<>();

        for (Entry nextItem : table[hash]) {
            if (nextItem.key.equals(key)) {
                V oldValue = nextItem.value;
                nextItem.value = value;
                return oldValue;
            }
        }

        table[hash].put(new Entry(key, value));
        size++;
        if (size > (LOAD_THRESHOLD * table.length))
            rehash();
        return null;
    }

    @Override
    public V remove(Object key) {
        int hash = myHash(key);

        if (table[hash] == null)
            return null;

        for (Entry nextItem : table[hash]) {
            if (nextItem.key.equals(key)) {
                V value = nextItem.value;
                table[hash].remove(nextItem);
                size--;
                if (table[hash].isEmpty())
                    table[hash] = null;
                return value;
            }
        }

        return null;
    }

    @Override
    public int size() {
        return size;
    }

    /**
     * Debug printing the whole map
     */
    @Override
    public void print() {
        System.out.println("Printing map...");
        for (int i = 0; i < table.length; i++) {
            if (table[i] != null) {
                for (Entry entry : table[i]) {
                    System.out.println(entry);
                }
            }
        }
    }

}