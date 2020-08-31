
/**
 * Tests for ExpressionTree
 */
public class Tester {

    private static void print(String str) {
        System.out.println(str);
    }

    public static void startTests() {
        t_general("+ + 10 * 5 15 20");
        t_general("10 5 15 * + 20 +");
        t_general("+ 5 2");
        t_general("5 2 +");
    }

    private static void t_general(String expression) {
        print("Testing for expression: " + expression);
        ExpressionTree expTree = new ExpressionTree(expression);
        print("toString (pre-order): " + expTree.toString());
        print("toString2 (post-order): " + expTree.toString2());
        print("eval: " + expTree.eval());
        print("\n");
    }
}