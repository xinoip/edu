import java.util.Iterator;

/**
 * NodeList is a custom List interface.
 * It has the the ability of manipulating List with existing nodes.
 * It can use existing nodes to add to list without creating new ones.
 * Or it can remove and return Nodes instead of the data.
 *
 * This way i can use the NodeList's removed nodes for other list.
 *
 * @param <E> data type of list
 */
public interface NodeList<E> {
    /**
     * @return size of the list
     */
    int size();

    /**
     * Printing operation for demo purposes
     */
    void print();

    /**
     * Get the Node at index.
     *
     * @param index list index for wanted node
     * @return node at index
     */
    Node<E> getNode(int index);

    /**
     * Inserts a given Node to given index
     *
     * @param index position to be inserted
     * @param node node to be inserted
     */
    void addNode(int index, Node<E> node);

    /**
     * Removes the node at given index and returns it
     *
     * @param index position to be removed
     * @return removed node
     */
    Node<E> removeNode(int index);

    /**
     * Overload for removing last Node and returning it
     *
     * @return removed node
     */
    Node<E> removeNode();

    /**
     * List is empty or not
     *
     * @return is empty
     */
    boolean isEmpty();

    /**
     * Get the data at index.
     *
     * @param index data position
     * @return data at index
     */
    E get(int index);

    /**
     * Overload for adding Node to end of list
     *
     * @param node node to be added
     */
    void addNode(Node<E> node);

    /**
     * Overload for adding element to end of list
     *
     * @param element to be added
     */
    void add(E element);

    /**
     * Creates new node and inserts it the given position
     * with given element value
     *
     * @param element to be added
     * @param index position to be added
     */
    void add(int index, E element);

    /**
     * Removes Node at position index and returns it's data
     *
     * @param index position to be removed
     * @return removed data
     */
    E remove(int index);

    /**
     * Overload for removing last element
     *
     * @return removed element
     */
    E remove();

    /**
     * Iterator for NodeList starting from head
     *
     * @return iterator pointing to head
     */
    Iterator<E> nodeIterator();

    /**
     * Iterator for NodeList starting from given index
     *
     * @param index start index
     * @return iterator pointing to index
     */
    Iterator<E> nodeIterator(int index);
}
