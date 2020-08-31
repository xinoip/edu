import java.util.Scanner;

/**
 * ExpressionTree is a BinaryTree structure for Post and Prefix expressions
 */
public class ExpressionTree extends BinaryTree<String> {

    /**
     * Flag for the last created ExpressionTree
     * Determining if it was postFix or preFix
     */
    private static boolean isPostFix;

    /**
     * Constructor for constructing the ExpressionTree with given expression String
     * It should be a valid expression and should be either Postfix or Prefix
     * 
     * @param expression Post or Pre fix expression in string form
     */
    ExpressionTree(String expression) {
        Scanner expScanner;

        if (Helper.isDigit(expression.charAt(0))) {
            isPostFix = true;
            expScanner = new Scanner(Helper.reverse(expression));
        } else {
            isPostFix = false;
            expScanner = new Scanner(expression);
        }

        root = readBinaryTree(expScanner).root;
        expScanner.close();
    }

    /**
     * Factory constructor for reading a Tree from given Scanner
     * 
     * @param scan the scanner containing the expression string
     * @return constructed tree
     */
    public static BinaryTree<String> readBinaryTree(Scanner scan) {
        String data = scan.next();
        Node<String> node = new Node<String>(data);

        if (Helper.isDigit(data.charAt(0))) {
            return new BinaryTree<String>(node);
        } else {
            if (!isPostFix) {
                node.left = readBinaryTree(scan).root;
                node.right = readBinaryTree(scan).root;
            } else {
                node.right = readBinaryTree(scan).root;
                node.left = readBinaryTree(scan).root;
            }
        }

        return new BinaryTree<>(node);
    }

    /**
     * Recursive solution for post order traverse, from given node
     * 
     * @param node start node
     * @param sb current string to pass recursively
     */
    private void postOrderTraverseHelper(Node<String> node, StringBuilder sb) {
        if (node == null) {
        } else {
            postOrderTraverseHelper(node.left, sb);
            postOrderTraverseHelper(node.right, sb);
            sb.append(node.data);
            sb.append(" ");
        }
    }

    /**
     * Traverse the tree in post order and return the string
     * 
     * @return tree in post order
     */
    private String postOrderTraverse() {
        StringBuilder sb = new StringBuilder();
        postOrderTraverseHelper(root, sb);
        return sb.toString();
    }

    /**
     * Recursive solution for pre order traverse, from given node
     * 
     * @param node start node
     * @param sb current string to pass recursively
     */
    private void preOrderTraverseHelper(Node<String> node, StringBuilder sb) {
        if (node == null) {
        } else {
            sb.append(node.data);
            sb.append(" ");
            preOrderTraverseHelper(node.left, sb);
            preOrderTraverseHelper(node.right, sb);
        }
    }

    /**
     * Traverse the tree in pre order and return the string
     * 
     * @return tree in pre order
     */
    private String preOrderTraverse() {
        StringBuilder sb = new StringBuilder();
        preOrderTraverseHelper(root, sb);
        return sb.toString();
    }

    /**
     * PostOrder version of the tree as string
     * 
     * @return post order tree
     */
    public String toString2() {
        return postOrderTraverse();
    }

    /**
     * PreOrder version of the tree as string
     * 
     * @return pre order tree
     */
    @Override
    public String toString() {
        return preOrderTraverse();
    }

    /**
     * Recursive solution for evaluating the ExpressionTree
     * 
     * @param root root of the expression tree
     * @return evaluation result
     */
    private int evalHelper(Node<String> root) {
        if (root != null) {
            if (Helper.isDigit(root.data.charAt(0))) {
                return Integer.parseInt(root.data);
            } else {
                int a = evalHelper(root.left);
                int b = evalHelper(root.right);

                switch (root.data.charAt(0)) {
                    case '+':
                        return a + b;
                    case '-':
                        return a - b;
                    case '/':
                        return a / b;
                    case '*':
                        return a * b;
                    default:
                        break;
                }
            }
        }

        return 0;
    }

    /**
     * Evaluate the ExpressionTree
     * 
     * @return evaluate result
     */
    public int eval() {
        return evalHelper(root);
    }
}