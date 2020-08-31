
public class BookHashTableOpen<K, V> implements KWHashMap<K, V> {

    private Entry<K, V>[] table;
    private static final int START_CAPACITY = 101;
    private double LOAD_THRESHOLD = 0.75;
    private int numKeys;
    private int numDeletes;
    private final Entry<K, V> DELETED = new Entry<K, V>(null, null);

    public BookHashTableOpen() {
        table = new Entry[START_CAPACITY];
    }

    public class Entry<K, V> {

        private K key;
        private V value;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V val) {
            V oldVal = value;
            value = val;
            return oldVal;
        }

    }

    private int find(Object key) {
        int index = key.hashCode() % table.length;
        if (index < 0) {
            index += table.length;
        }

        while (table[index] != null && !key.equals(table[index].key)) {
            index++;
            if (index >= table.length)
                index = 0;
        }
        return index;
    }

    private void rehash() {
        Entry<K, V>[] oldTable = table;

        table = new Entry[2 * oldTable.length + 1];

        numKeys = 0;
        numDeletes = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if (oldTable[i] != null && oldTable[i] != DELETED) {
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
        return (numKeys > 0) ? false : true;
    }

    @Override
    public V put(K key, V value) {
        int index = find(key);

        if (table[index] == null) {
            table[index] = new Entry<K, V>(key, value);
            numKeys++;

            double loadFactor = (double) (numKeys + numDeletes) / table.length;
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

        table[index] = DELETED;
        ++numDeletes;
        --numKeys;
        return value;
    }

    @Override
    public int size() {
        return numKeys;
    }

    @Override
    public void print() {
    }

}
