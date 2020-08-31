/**
 * Custom hash open table implementation with double hashing
 * 
 * @param <K> key type, should be comparable
 * @param <V> value type
 */
public class HashTableOpen<K extends Comparable<K>, V> implements KWHashMap<K, V> {
    /**
     * Table is just array of entries
     * for implementing open table
     */
    private Entry[] table;
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
    private double LOAD_THRESHOLD = 0.75;
    /**
     * Deleted count for calculating load factor
     */
    private int deleteCount;

    /**
     * Default constructor for initializing empty map
     */
    public HashTableOpen() {
        table = new HashTableOpen.Entry[CAPACITY];
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
         * @param key   key of new entry
         * @param value value of new entry
         */
        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public boolean isDeleted() {
            return key == null && value == null;
        }

        public void setAsDeleted() {
            key = null;
            value = null;
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

    /**
     * Find used for open table implementation
     * It uses double hash probing
     * 
     * @param key key to hash
     * @return found hash
     */
    private int find(Object key) {
        int hash1 = myHash(key);
        int hash2 = myHash(hash1);

        while (table[hash1] != null && !key.equals(table[hash1].key)) {
            hash1 += hash2 * 2;
            if (hash1 >= table.length)
                hash1 = 0;
        }
        return hash1;
    }

    /**
     * Rehash implementation
     */
    private void rehash() {
        Entry[] oldTable = table;

        table = new HashTableOpen.Entry[2 * oldTable.length + 1];

        size = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if (oldTable[i] != null && !oldTable[i].isDeleted()) {
                put(oldTable[i].key, oldTable[i].value);
            }
        }
    }

    @Override
    public V get(Object key) {
        int index = find(key);

        if (table[index] != null)
            return table[index].value;
        else
            return null;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public V put(K key, V value) {
        int index = find(key);

        if (table[index] == null) {
            table[index] = new HashTableOpen.Entry(key, value);
            size++;

            double loadFactor = (double) (size + deleteCount) / table.length;
            if (loadFactor > LOAD_THRESHOLD)
                rehash();
            return null;
        }
        V oldVal = table[index].value;
        table[index].value = value;
        return oldVal;
    }

    @Override
    public V remove(Object key) {
        int index = find(key);
        V value = get(key);

        if (value == null)
            return null;

        table[index].setAsDeleted();
        deleteCount++;
        size--;
        return value;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void print() {
        System.out.println("Printing map...");
        for (Entry entry : table) {
            if (entry != null) {
                if (!entry.isDeleted()) {
                    System.out.println(entry);
                }
            }
        }
    }

}
