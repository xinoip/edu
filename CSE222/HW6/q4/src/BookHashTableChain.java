import java.util.LinkedList;

/**
 * HashTableChain From book
 * 
 * @param <K>
 * @param <V>
 */
public class BookHashTableChain<K, V> implements KWHashMap<K, V> {
    private LinkedList<Entry<K, V>>[] table;
    private int numKeys;
    private static final int CAPACITY = 101;
    private static final double LOAD_THRESHOLD = 3.0;

    public BookHashTableChain() {
        table = new LinkedList[CAPACITY];
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

    @Override
    public V get(Object key) {
        int index = key.hashCode() % table.length;
        if (index < 0)
            index += table.length;
        if (table[index] == null)
            return null;

        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.key.equals(key))
                return nextItem.value;
        }
        return null;
    }

    private void rehash() {
        LinkedList<Entry<K, V>>[] oldTable = table;

        table = new LinkedList[2 * oldTable.length + 1];

        numKeys = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if (oldTable[i] != null) {
                for (int j = 0; j < oldTable[i].size(); j++) {
                    Entry<K, V> e = oldTable[i].get(j);
                    put(e.key, e.value);
                }
            }
        }
    }

    @Override
    public boolean isEmpty() {
        return (numKeys > 0) ? false : true;
    }

    @Override
    public V put(K key, V value) {
        int index = key.hashCode() % table.length;
        if (index < 0)
            index += table.length;
        if (table[index] == null)
            table[index] = new LinkedList<Entry<K, V>>();

        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.key.equals(key)) {
                V oldVal = nextItem.value;
                nextItem.setValue(value);
                return oldVal;
            }
        }

        table[index].addFirst(new Entry<K, V>(key, value));
        numKeys++;
        if (numKeys > (LOAD_THRESHOLD * table.length))
            rehash();
        return null;
    }

    @Override
    public V remove(Object key) {
        int index = key.hashCode() % table.length;
        if (index < 0)
            index += table.length;
        if (table[index] == null)
            return null;

        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.key.equals(key)) {
                V value = nextItem.value;
                table[index].remove(nextItem);
                --numKeys;
                if (table[index].isEmpty())
                    table[index] = null;
                return value;
            }
        }
        return null;
    }

    @Override
    public int size() {
        return numKeys;
    }

    @Override
    public void print() {
    }

}
