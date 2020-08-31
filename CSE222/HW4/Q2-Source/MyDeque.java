import java.util.AbstractCollection;
import java.util.Collection;
import java.util.Deque;
import java.util.Iterator;

/**
 * Custom Deque implementation with dual-DoubleLinkedLists.
 * One DoubleLinkedList is for Deque data
 * Other is for holding removed elements.
 *
 * It uses removed elements before creating new nodes for adding to deque.
 *
 * @param <E> data type of deque
 */
public class MyDeque<E> extends AbstractCollection<E> implements Deque<E> {
    /**
     * Deque data NodeList
     */
    private NodeList<E> deque;
    /**
     * NodeList holding removed elements
     */
    private NodeList<E> removed;

    /**
     * Default constructor initializes NodeLists as DoubleLinkedLists
     */
    MyDeque() {
        deque = new DoubleLinkedList<>();
        removed = new DoubleLinkedList<>();
    }

    /**
     * Printing deque data for demo purposes
     */
    public void printDequeStatus() {
        System.out.print("DequeStatus: ");
        deque.print();
    }

    /**
     * Printing removed data for demo purposes
     */
    public void printRemovedStatus() {
        System.out.print("RemovedStatus: ");
        removed.print();
    }

    /**
     * If there is no removed elements in removed NodeList
     * then add an element by creating a New node.
     *
     * else use the existing node from removed list, change its data,
     * and add that node without creating new one.
     *
     * @param e new element to be inserted
     */
    @Override
    public void addFirst(E e) {
        if(removed.isEmpty()) {
            deque.add(0, e);
        } else {
            Node<E> existingNode = removed.removeNode();
            existingNode.data = e;
            deque.addNode(0, existingNode);
        }
    }

    /**
     * Same system for adding to end of deque
     *
     * @param e new element to be inserted
     */
    @Override
    public void addLast(E e) {
        if(removed.isEmpty()) {
            deque.add(e);
        } else {
            Node<E> existingNode = removed.removeNode();
            existingNode.data = e;
            deque.addNode(existingNode);
        }
    }

    /**
     * Same system for adding to start of deque
     *
     * This is exception free, it handles the errors with boolean returns.
     *
     * @param e new element to be inserted
     */
    @Override
    public boolean offerFirst(E e) {
        try {
            addFirst(e);
            return true;
        } catch (Exception ex) {
            return false;
        }
    }

    /**
     * Same system for adding to end of deque
     *
     * This is exception free, it handles the errors with boolean returns.
     *
     * @param e new element to be inserted
     */
    @Override
    public boolean offerLast(E e) {
        try {
            addLast(e);
            return true;
        } catch (Exception ex) {
            return false;
        }
    }

    /**
     * Remove first element of deque and store it inside removed elements list as Node
     *
     * @return removed elements data
     */
    @Override
    public E removeFirst() {
        Node<E> removedNode = deque.removeNode(0);
        removed.addNode(removedNode);
        return removedNode.data;
    }

    /**
     * Remove last element of deque and store it inside removed elements list as Node
     *
     * @return removed elements data
     */
    @Override
    public E removeLast() {
        Node<E> removedNode = deque.removeNode();
        removed.addNode(removedNode);
        return removedNode.data;
    }

    /**
     * Remove first element of deque and store it inside removed elements list as Node
     *
     * This is exception free, it handles the errors with boolean returns.
     *
     * @return removed elements data
     */
    @Override
    public E pollFirst() {
        try {
            return removeFirst();
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * Remove last element of deque and store it inside removed elements list as Node
     *
     * This is exception free, it handles the errors with boolean returns.
     *
     * @return removed elements data
     */
    @Override
    public E pollLast() {
        try {
            return removeLast();
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * Return first element of deque
     *
     * @return first element
     */
    @Override
    public E getFirst() {
        return deque.get(0);
    }

    /**
     * Return last element of deque
     *
     * @return last element
     */
    @Override
    public E getLast() {
        return deque.get(deque.size() - 1);
    }

    /**
     * Return first element of deque
     *
     * This is exception free, it handles the by returning null on error.
     *
     * @return first element
     */
    @Override
    public E peekFirst() {
        try {
            return getFirst();
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * Return last element of deque
     *
     * This is exception free, it handles the errors by returning null on error.
     *
     * @return last element
     */
    @Override
    public E peekLast() {
        try {
            return getLast();
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * Remove first occurrence of given Object
     * If object is not found return false;
     *
     * @return remove success
     */
    @Override
    public boolean removeFirstOccurrence(Object o) {
        for(int i = 0; i < deque.size(); i++) {
            E data = deque.get(i);
            if(data.equals(o)) {
                try {
                    Node<E> removedNode = deque.removeNode(i);
                    removed.addNode(removedNode);
                    return true;
                } catch (Exception ex) {
                    return false;
                }
            }
        }
        return false;
    }

    /**
     * Remove last occurrence of given Object
     * If object is not found return false;
     *
     * @return remove success
     */
    @Override
    public boolean removeLastOccurrence(Object o) {
        for(int i = deque.size() - 1; i >= 0; i--) {
            E data = deque.get(i);
            if(data.equals(o)) {
                try {
                    Node<E> removedNode = deque.removeNode(i);
                    removed.addNode(removedNode);
                    return true;
                } catch (Exception ex) {
                    return false;
                }
            }
        }
        return false;
    }

    /**
     * Adds to end of deque the given element
     *
     * This is exception free, it handles the errors with boolean returns.
     *
     * @return addition success
     */
    @Override
    public boolean add(E e) {
        try {
            addLast(e);
            return true;
        } catch (Exception ex) {
            return false;
        }
    }

    /**
     * It is equivalent of offerLast method
     *
     * @param e element to be added
     * @return success status
     */
    @Override
    public boolean offer(E e) {
        return offerLast(e);
    }

    /**
     * It is equivalent of pollFirst method
     *
     * @return success status as removed element, null or not
     */
    @Override
    public E remove() {
        try {
            return removeFirst();
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * It is equivalent of pollFirst method
     *
     * @return success status as removed element, null or not
     */
    @Override
    public E poll() {
        return pollFirst();
    }

    /**
     * It is equivalent of getFirst method
     *
     * @return first element of deque
     */
    @Override
    public E element() {
        return getFirst();
    }

    /**
     * It is equivalent of peekFirst method
     *
     * This is exception free, it handles the errors by returning null on error.
     *
     * @return success status as removed element, null or not
     */
    @Override
    public E peek() {
        return peekFirst();
    }

    /**
     * Clears all of the deque data.
     * Does not clear the removed list, instead, populates it.
     */
    @Override
    public void clear() {
        while(!deque.isEmpty()) {
            pop();
        }
    }

    /**
     * It is equivalent of addFirst method
     *
     * @param e element to add
     */
    @Override
    public void push(E e) {
        addFirst(e);
    }

    /**
     * It is equivalent of removeFirst method
     *
     * @return removed element
     */
    @Override
    public E pop() {
        return removeFirst();
    }

    /**
     * It is equivalent of removeFirstOccurrence method
     *
     * @param o element to remove
     * @return success status
     */
    @Override
    public boolean remove(Object o) {
        return removeFirstOccurrence(o);
    }

    /**
     * Returns true if the given object exists in deque
     *
     * @param o object to search for
     * @return existing or not
     */
    @Override
    public boolean contains(Object o) {
        for(int i = 0; i < deque.size(); i++) {
            E data = deque.get(i);
            if(data.equals(o)) {
                return true;
            }
        }
        return false;
    }

    /**
     * @return current size of deque
     */
    @Override
    public int size() {
        return deque.size();
    }

    /**
     * @return isEmpty deque
     */
    @Override
    public boolean isEmpty() {
        return deque.isEmpty();
    }

    /**
     * Return iterator to start of deque
     *
     * @return iterator to start of deque
     */
    @Override
    public Iterator<E> iterator() {
        return deque.nodeIterator();
    }

    /**
     * Returns iterator to end of deque
     *
     * @return iterator to end of deque
     */
    @Override
    public Iterator<E> descendingIterator() {
        return deque.nodeIterator(size() - 1);
    }
}
