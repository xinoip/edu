/**
 * Node class used for NodeList.
 * NodeList lets user to re-use removed Nodes, add existing Nodes without creating new Nodes.
 *
 * @param <T> data type of Node
 */
public class Node<T> {
    /**
     * Next link
     */
    public Node<T> next;

    /**
     * Previous link
     */
    public Node<T> prev;

    /**
     * Inner data
     */
    public T data;

    /**
     * Default constructor for empty node
     */
    Node() {
        this.next = null;
        this.prev = null;
        this.data = null;
    }

    /**
     * Constructor for custom node
     * @param next next link
     * @param prev previous link
     * @param data inner data
     */
    Node(Node<T> next, Node<T> prev, T data) {
        this.next = next;
        this.prev = prev;
        this.data = data;
    }
}