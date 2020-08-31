import java.util.Iterator;
import java.util.Stack;

/**
 * Custom BST Structure that is fully iterable and has an Iterator.
 * 
 * @param <T> data type
 */
public class MyBst<T extends Comparable<T>> implements Iterable<T> {
    /**
     * Root of BST
     */
    private Node root;

    /**
     * Size of BST
     */
    private int size;

    /**
     * Node structure of BST
     */
    private class Node {
        /**
         * Current value, also used as key for comparisons
         */
        private T value;
        /**
         * Left node pointer
         */
        private Node left;
        /**
         * Right node pointer
         */
        private Node right;

        /**
         * Default constructor for creating node with value
         * 
         * @param value new nodes value
         */
        Node(T value) {
            this.value = value;
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Puts the given value into bst
     * 
     * @param value new value to put
     */
    public void put(T value) {
        if (root == null) {
            root = new Node(value);
            size++;
        } else {
            putHelper(root, value);
        }
    }

    /**
     * Recursive solution for putting value into bst
     * 
     * @param node current root
     * @param value new value to put
     */
    private void putHelper(Node node, T value) {
        int comparison = value.compareTo(node.value);
        if (comparison < 0) {
            if (node.left == null) {
                node.left = new Node(value);
                size++;
            } else {
                putHelper(node.left, value);
            }
        } else {
            if (node.right == null) {
                node.right = new Node(value);
                size++;
            } else {
                putHelper(node.right, value);
            }
        }
    }

    public T remove(T value) {
        if(root == null) {
            return null;
        } else if(root.value.equals(value)) {
            T removed = root.value;
            root = null;
            return removed;
        } else {
            return removeHelper(root, value);
        }
    }

    private T removeHelper(Node node, T value) {
        if(node == null)
            return null;

        int comparison = value.compareTo(node.value);
        
        if (comparison < 0) {
            return removeHelper(node.left, value);
        } else if(comparison > 0) {
            return removeHelper(node.right, value);
        } else {
            T oldValue = node.value;
            node = null;
            size--;
            return oldValue;
        }
    }

    /**
     * Custom Iterator for iterating over BST, pre-order
     */
    @Override
    public Iterator<T> iterator() {
        return new BSTIterator();
    }

    /**
     * Custom Iterator for iterating over BST, pre-order
     */
    private class BSTIterator implements Iterator<T> {
        /**
         * Stack for short-memory of iterated things
         */
        private Stack<Node> stack = new Stack<Node>();

        BSTIterator() {
            pushLeft(root);
        }

        /**
         * Go to left, add previous to stack
         * 
         * @param node root
         */
        private void pushLeft(Node node) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
        }

        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        @Override
        public T next() {
            Node node = stack.pop();
            pushLeft(node.right);
            return node.value;
        }
    }
}