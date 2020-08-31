import java.util.Iterator;

/**
 * AbstractNodeList is an Abstract implementation of NodeList
 * It implements, implementable functions for common Lists,
 * to eliminate code repetition.
 *
 * @param <E> data type of list
 */
public abstract class AbstractNodeList<E> implements NodeList<E> {

    /**
     * isEmpty implemented in Abstract manner
     *
     * @return is empty
     */
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * get can be implemented if getNode provided
     *
     * @param index data position
     * @return data at index
     */
    public E get(int index) {
        return getNode(index).data;
    }

    /**
     * Overload for adding Node to end of list
     *
     * @param node node to be added
     */
    public void addNode(Node<E> node) {
        int index = size();
        if(isEmpty())
            index = 0;

        addNode(index, node);
    }

    /**
     * Overload for adding element to end of list
     *
     * @param element to be added
     */
    public void add(E element) {
        int index = size();
        if(isEmpty())
            index = 0;

        addNode(index, new Node<E>(null, null, element));
    }

    /**
     * add can be implemented if addNode provided
     *
     * @param index position to be added
     * @param element to be added
     */
    public void add(int index, E element) {
        addNode(index, new Node<E>(null, null, element));
    }

    /**
     * add can be implemented if removeNode provided
     *
     * @param index position to be removed
     * @return removed element
     */
    public E remove(int index) {
        return removeNode(index).data;
    }

    /**
     * Overload for removing last element of List
     *
     * @return removed element
     */
    public E remove() {
        return removeNode(size() - 1).data;
    }

    /**
     * Overload for removing last Node of List
     *
     * @return removed Node
     */
    public Node<E> removeNode() {
        return removeNode(size() - 1);
    }

    /**
     *  Custom iterator implementation for NodeList.
     *  It iterates over nodes and has the ability of getting data as whole Node
     */
    public class NodeIterator implements Iterator<E> {

        /**
         * Currently pointed index
         */
        protected int currentIndex = 0;

        /**
         * Default constructor starts from head
         */
        NodeIterator() {
            currentIndex = 0;
        }

        /**
         * Constructor for starting from any index
         * @param index index
         */
        NodeIterator(int index) {
            currentIndex = index;
        }

        /**
         * Check if there are nodes next
         *
         * @return has any next element
         */
        @Override
        public boolean hasNext() {
            return !(currentIndex + 1 > size());
        }

        /**
         * Return current data and go next
         *
         * @return current data
         */
        @Override
        public E next() {
            return getNode(currentIndex++).data;
        }

        /**
         * Return current node and go next
         *
         * @return current node
         */
        public Node<E> nextNode() {
            return getNode(currentIndex++);
        }

        /**
         * Check if there is a previous element
         *
         * @return has previous
         */
        public boolean hasPrevious() {
            return !(currentIndex - 1 < -1);
        }

        /**
         * Return current element and go back
         *
         * @return current element
         */
        public Node<E> previous() {
            return getNode(currentIndex--);
        }

        /**
         * Return next index
         *
         * @return next index
         */
        public int nextIndex() {
            return currentIndex + 1;
        }

        /**
         * Return previous index
         *
         * @return previous index
         */
        public int previousIndex() {
            return currentIndex - 1;
        }

        /**
         * Removes last returned element
         */
        @Override
        public void remove() {
            removeNode(previousIndex());
        }
    }

    /**
     * Custom implementation of iterator for NodeIterator
     *
     * @return new NodeIterator to start
     */
    @Override
    public Iterator<E> nodeIterator() {
        return new NodeIterator();
    }

    /**
     * Custom implementation of iterator for NodeIterator
     *
     * @param index start index
     * @return new NodeIterator to given index
     */
    @Override
    public Iterator<E> nodeIterator(int index) {
        return new NodeIterator(index);
    }
}
