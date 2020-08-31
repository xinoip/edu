import java.util.*;


/**
 * LinkedArrayList is a List structure.
 * It is a DoubleLinkedList of Arrays.
 * Like memory segments.
 *
 * @param <E> Type of the data to hold
 */
public class LinkedArrayList<E> extends AbstractList<E> implements List<E> {

    /**
     * Nodes array capacity
     */
    private final static int ARR_CAP = 10;

    /**
     * Head reference
     */
    private Node<E> head;

    /**
     * Tail reference
     */
    private Node<E> tail;

    /**
     * Current number of elements in list
     */
    private int currentSize;

    /**
     * Initializes a empty list
     */
    public LinkedArrayList() {
        this.head = null;
        this.tail = null;
        this.currentSize = 0;
    }

    /**
     * Nodes containing arrays.
     *
     * @param <T> type of data
     */
    class Node<T> {

        /**
         * Data array
         */
        public T[] arr;

        /**
         * Reference to next node
         */
        public Node<T> next;

        /**
         * Reference to previous node
         */
        public Node<T> prev;

        /**
         * Initialize empty node with empty array
         */
        public Node() {
            next = null;
            prev = null;
            arr = (T[]) new Object[ARR_CAP];
        }

        /**
         * Check if nodes array is fully empty.
         *
         * @return is the containing array empty or not
         */
        public boolean isEmpty() {
            int countNull = 0;
            for(int i = 0; i < 10; i++) {
                if(arr[i] == null) {
                    countNull++;
                }
            }

            return countNull == 10;
        }

        /**
         * Check if nodes array has at least one empty space
         *
         * @return has one empty space
         */
        public boolean containsEmpty() {
            for(int i = 0; i < 10; i++) {
                if(arr[i] == null) {
                    return true;
                }
            }

            return false;
        }
    }

    /**
     * LinkedArrayListIterator is iterator implementation for list
     */
    class LinkedArrayListIterator implements Iterator<E> {

        /**
         * Currently pointed index
         */
        protected int currentIndex = 0;

        /**
         * Check if there is a next element
         *
         * @return has valid next element
         */
        @Override
        public boolean hasNext() {
            return get(currentIndex + 1) != null;
        }

        /**
         * Return current element and go next
         *
         * @return current element
         */
        @Override
        public E next() {
            return get(currentIndex++);
        }
    }

    /**
     * LinkedArrayListListIterator is ListIterator implementation for list
     */
    class LinkedArrayListListIterator extends LinkedArrayListIterator implements ListIterator<E> {

        /**
         * Check if there is a previous element
         *
         * @return has previous
         */
        @Override
        public boolean hasPrevious() {
            try {
                return get(currentIndex - 1) != null;
            } catch(Exception e) {
                return false;
            }
        }

        /**
         * Return current element and go back
         *
         * @return current element
         */
        @Override
        public E previous() {
            return get(currentIndex--);
        }

        /**
         * Return next index
         *
         * @return next index
         */
        @Override
        public int nextIndex() {
            return currentIndex + 1;
        }

        /**
         * Return previous index
         *
         * @return previous index
         */
        @Override
        public int previousIndex() {
            return currentIndex - 1;
        }

        /**
         * Remove with ListIterator is unsupported
         */
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }

        /**
         * Set with ListIterator is unsupported
         */
        @Override
        public void set(E e) {
            throw new UnsupportedOperationException();
        }

        /**
         * Add with ListIterator is unsupported
         */
        @Override
        public void add(E e) {
            throw new UnsupportedOperationException();
        }
    }

    /**
     * Constructs a string that represents data structure.
     * String contains nodes array status, nodes status, and links.
     *
     * @return status of lists structure as string
     */
    @Override
    public String toString() {
        Node<E> currentNode = head;
        if(currentNode == null)
            return "empty";

        String rtr = "";

        while(true) {
            if(currentNode == null)
                break;

            rtr += "[";
            for(int i = 0; i < ARR_CAP; i++) {
                E currentElement = currentNode.arr[i];
                if(currentElement == null) {
                    rtr += "*";
                } else {
                    rtr += currentElement.toString();
                }

                if(i != ARR_CAP - 1) {
                    rtr += ",";
                }
            }
            rtr += "]->";

            currentNode = currentNode.next;
        }

        return rtr;
    }

    /**
     *
     * @return current size of list
     */
    @Override
    public int size() {
        return currentSize;
    }

    /**
     *
     * @return is list empty or not
     */
    @Override
    public boolean isEmpty() {
        return head == null;
    }

    /**
     *
     * @return iterator to start of list
     */
    @Override
    public Iterator<E> iterator() {
        return new LinkedArrayListIterator();
    }

    /**
     * Insert element to given index and shift elements forward.
     * If array is exhausted, inserts new node.
     * If array is not exhausted, just shifts that array forward.
     *
     * @param index position to add
     * @param e element to add
     */
    @Override
    public void add(int index, E e) throws  IndexOutOfBoundsException {
        if(index < 0 || index > size())
            throw new IndexOutOfBoundsException();

        Node<E> currentNode = head;
        if(currentNode == null)
            throw new IndexOutOfBoundsException();

        int nodeIndex = index / ARR_CAP;
        int arrIndex = index % ARR_CAP;

        for(int i = 0; i < nodeIndex; i++) {
            if(currentNode.next == null)
                throw new IndexOutOfBoundsException();
            currentNode = currentNode.next;
        }

        if(currentNode.containsEmpty()) {
            // current array has empty place

            // insert and shift forward
            E[] result = (E[]) new Object[ARR_CAP];
            for(int i = 0; i < arrIndex; i++)
                result[i] = currentNode.arr[i];
            result[arrIndex] = e;
            for(int i = arrIndex + 1; i < ARR_CAP; i++)
                result[i] = currentNode.arr[i - 1];

            currentNode.arr = result;
        } else {
            // current array is exhausted, insert new array
            Node tmpNode = new Node<E>();
            tmpNode.prev = currentNode;
            tmpNode.next = currentNode.next;
            currentNode.next = tmpNode;

            tmpNode.arr[0] = currentNode.arr[ARR_CAP - 1];

            E[] result = (E[]) new Object[ARR_CAP];
            for(int i = 0; i < arrIndex; i++)
                result[i] = currentNode.arr[i];
            result[arrIndex] = e;
            for(int i = arrIndex + 1; i < ARR_CAP; i++)
                result[i] = currentNode.arr[i - 1];

            currentNode.arr = result;
        }
    }

    /**
     * Add element to end of the list.
     * If last nodes array is exhausted, inserts new node.
     *
     * @param e element to add
     * @return returns always true
     */
    @Override
    public boolean add(E e) {
        if(isEmpty()) {
            // List is empty, insert new array and insert element to array
            head = new Node<E>();
            tail = head;
            head.arr[0] = e;
        } else {
            // List is not empty, check the tails array
            boolean placed = false;
            for(int i = 0; i < ARR_CAP; i++) {
                // try to find a empty space in array and place it
                if(tail.arr[i] == null) {
                    tail.arr[i] = e;
                    placed = true;
                    break;
                }
            }

            // if tail array was full, add new node after tail and place the element
            // point tail to new node
            if(!placed) {
                Node tmpNode = new Node<E>();
                tmpNode.prev = tail;
                tail.next = tmpNode;
                tail = tail.next;
                tail.arr[0] = e;
            }
        }

        currentSize++;
        return true;
    }

    /**
     * Find and remove first occurrence of given element from list.
     * It shifts back the arrays after removing.
     * Also can delete the node if node is empty, after removal.
     *
     * @param o element to remove
     * @return success status
     */
    @Override
    public boolean remove(Object o) {
        if(isEmpty()) {
            return false;
        }

        Node<E> currentNode = head;
        while (currentNode != null) {
            for(int i = 0; i < ARR_CAP; i++) {
                if(currentNode.arr[i].equals(o)) {
                    currentNode.arr[i] = null;
                    if(currentNode.isEmpty()) {
                        if(currentNode.prev == null) {
                            //currentNode is head
                            head = currentNode.next;
                            head.prev = null;
                        } else if(currentNode.next == null) {
                            //currentNode is tail
                            tail = currentNode.prev;
                            tail.next = null;
                        } else {
                            //currentNode is a node at middle
                            currentNode.prev.next = currentNode.next;
                            currentNode.next.prev = currentNode.prev;
                        }

                        currentSize--;
                        return true;
                    }

                    // shift back
                    for(int j = i; j < ARR_CAP; j++) {
                        if(j + 1 >= ARR_CAP) {
                            break;
                        }
                        currentNode.arr[j] = currentNode.arr[j+1];
                        currentNode.arr[j+1] = null;
                    }

                    return true;

                }
            }

            currentNode = currentNode.next;
        }

        return false;
    }

    /**
     * Fully clear the list
     */
    @Override
    public void clear() {
        while(!isEmpty())
            remove(0);
    }

    /**
     * Get element from index
     *
     * @param index elements position
     * @return element at index
     */
    @Override
    public E get(int index) {
        if(index < 0)
            throw new IndexOutOfBoundsException();

        Node<E> currentNode = head;
        if(currentNode == null)
            return null;

        int nodeIndex = index / ARR_CAP;
        int arrIndex = index % ARR_CAP;

        for(int i = 0; i < nodeIndex; i++) {
            if(currentNode.next == null)
                return null;
            currentNode = currentNode.next;
        }

        return currentNode.arr[arrIndex];
    }

    /**
     * Remove element at given index
     *
     * @param index element position
     * @return removed element
     */
    @Override
    public E remove(int index) {
        if(isEmpty()) {
            return null;
        }

        Node<E> currentNode = head;
        if(currentNode == null)
            return null;

        int nodeIndex = index / ARR_CAP;
        int arrIndex = index % ARR_CAP;

        for(int i = 0; i < nodeIndex; i++) {
            if(currentNode.next == null)
                return null;
            currentNode = currentNode.next;
        }

        E rtr = currentNode.arr[arrIndex];

        currentNode.arr[arrIndex] = null;
        if(currentNode.isEmpty()) {
            if(currentNode.prev == null) {
                //currentNode is head
                head = currentNode.next;
                if(head == null)
                    return rtr;
                head.prev = null;
            } else if(currentNode.next == null) {
                //currentNode is tail
                tail = currentNode.prev;
                tail.next = null;
            } else {
                //currentNode is a node at middle
                currentNode.prev.next = currentNode.next;
                currentNode.next.prev = currentNode.prev;
            }

            return rtr;
        }

        // shift back
        for(int j = arrIndex; j < ARR_CAP; j++) {
            if(j + 1 >= ARR_CAP) {
                break;
            }
            currentNode.arr[j] = currentNode.arr[j+1];
            currentNode.arr[j+1] = null;
        }

        return rtr;
    }

    /**
     * @return ListIterator to start of list
     */
    @Override
    public ListIterator<E> listIterator() {
        return new LinkedArrayListListIterator();
    }

    /**
     * @param index position pointing of iterator
     * @return ListIterator to given index of list
     */
    @Override
    public ListIterator<E> listIterator(int index) {
        LinkedArrayListListIterator rtr = new LinkedArrayListListIterator();
        for(int i = 0; i < index; i++) {
            rtr.next();
        }

        return rtr;
    }
}
