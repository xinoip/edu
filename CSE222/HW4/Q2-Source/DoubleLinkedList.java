/**
 * DoubleLinkedList is an AbstractNodeList which is implemented in DoublyLinkedList manner.
 * It lets user to re-use existing nodes by exposing addNode and removeNode functions,
 * which takes Node as parameter.
 *
 * This way user of this class can store removed Nodes and when adding new ones, may pass the removed ones as parameter.
 *
 *
 * NOTE THAT: this does not automatically use removed nodes. This class only gives the user an ability to manipulate
 * removed nodes and the list with existing nodes.
 *
 * NOTE THAT: this class does not do ANY memory allocations. This class only uses existing Nodes for adding/removing,
 * by from given parameters.
 *
 * @param <E> data of DoubleLinkedList
 */
public class DoubleLinkedList<E> extends AbstractNodeList<E> {
    /**
     * Head pointer
     */
    private Node<E> head;
    /**
     * Tail pointer
     */
    private Node<E> tail;
    /**
     * Current size
     */
    private int size;

    /**
     * Default constructor initialize empty LinkedList
     */
    DoubleLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    /**
     * Printing for debug purposes
     */
    @Override
    public void print() {
        Node<E> nodePtr = head;
        System.out.print("head -> ");
        while(nodePtr != null) {
            System.out.print(nodePtr.data.toString() + " -> ");
            nodePtr = nodePtr.next;
        }
        System.out.println("tail");
    }

    /**
     * @return current size of lis
     */
    @Override
    public int size() {
        return size;
    }

    /**
     * Gets the Node at index and returns it
     *
     * @param index list index for wanted node
     * @return node at index
     * @throws IndexOutOfBoundsException when index is not valid
     */
    @Override
    public Node<E> getNode(int index) throws IndexOutOfBoundsException {
        if(index >= size() || index < 0)
            throw new IndexOutOfBoundsException();

        Node<E> nodePtr = head;
        for(int i = 0; i < index; i++) {
            nodePtr = nodePtr.next;
        }
        return nodePtr;
    }

    /**
     * Inserts the given Node to given position
     *
     * @param index position to be inserted
     * @param newNode node to be inserted
     */
    @Override
    public void addNode(int index, Node<E> newNode) {
        if(index > size() || index < 0)
            throw new IndexOutOfBoundsException();
        if(index == 0) {
            addToHead(newNode);
            return;
        }
        if(index == size()) {
            addToTail(newNode);
            return;
        }

        Node<E> nodePtr = getNode(index);

        Node<E> next = nodePtr;
        Node<E> prev = nodePtr.prev;

        prev.next = newNode;
        newNode.prev = prev;
        newNode.next = next;
        next.prev = newNode;

        size++;
    }

    /**
     * Removed and returns the Node at position index
     *
     * @param index position to be removed
     * @return removed Node
     */
    @Override
    public Node<E> removeNode(int index) {
        if(isEmpty())
            throw new IndexOutOfBoundsException();
        if(index >= size() || index < 0)
            throw new IndexOutOfBoundsException();
        if(index == 0)
            return removeFromHead();
        if(index == size() - 1)
            return removeFromTail();

        Node<E> nodePtr = getNode(index);
        Node<E> next = nodePtr.next;
        Node<E> prev = nodePtr.prev;
        nodePtr.next = null;
        nodePtr.prev = null;
        next.prev = prev;
        prev.next = next;

        size--;
        return nodePtr;
    }

    /**
     * Helper function for adding a Node before head
     *
     * @param newNode Node to be added
     */
    private void addToHead(Node<E> newNode) {
        if(isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            head.prev = newNode;
            newNode.prev = null;
            newNode.next = head;
            head = newNode;
        }

        size++;
    }

    /**
     * Helper function for adding a Node after tail
     *
     * @param newNode Node to be added
     */
    private void addToTail(Node<E> newNode) {
        if(isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            newNode.next = null;
            tail = newNode;
        }

        size++;
    }

    /**
     * Helper function for removing the head
     *
     * @return removed head as Node
     * @throws IndexOutOfBoundsException if the list is empty
     */
    private Node<E> removeFromHead() throws IndexOutOfBoundsException {
        if(isEmpty())
            throw new IndexOutOfBoundsException();
        Node<E> data = head;

        if(size == 1) {
            head = null;
            tail = null;
        } else {
            Node<E> newHead = head.next;
            newHead.prev = null;
            head.next = null;
            head = newHead;
        }

        size--;
        return data;
    }

    /**
     * Helper function for removing the tail
     *
     * @return removed tail as Node
     * @throws IndexOutOfBoundsException if the list is empty
     */
    private Node<E> removeFromTail() throws IndexOutOfBoundsException {
        if(isEmpty())
            throw new IndexOutOfBoundsException();
        Node<E> data = tail;

        if(size == 1) {
            head = null;
            tail = null;
        } else {
            Node<E> newTail = tail.prev;
            newTail.next = null;
            tail.prev = null;
            tail = newTail;
        }

        size--;
        return data;
    }
}
