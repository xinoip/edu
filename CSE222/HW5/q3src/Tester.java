
/**
 * Tests for AgeSearchTree
 */
public class Tester {

    private static void print(String str) {
        System.out.println(str);
    }
    
    public static void startTests() {
        t_addData();
        print("");
        t_removeData();
        print("");
        t_olderYoungerData();
        print("");
        t_find();
        print("");
    }

    public static void t_addData() {
        print("Adding some data to demonstrate toString and add functions: ");
        AgeSearchTree ageTree = new AgeSearchTree();
        ageTree.add(new AgeData(10));
        ageTree.add(new AgeData(20));
        ageTree.add(new AgeData(5));
        ageTree.add(new AgeData(15));
        ageTree.add(new AgeData(10));
        print(ageTree.toString());
    }

    public static void t_removeData() {
        print("Removing AgeData to demonstrate decrementing: ");
        AgeSearchTree ageTree = new AgeSearchTree();
        ageTree.add(new AgeData(10));
        ageTree.add(new AgeData(20));
        ageTree.add(new AgeData(5));
        ageTree.add(new AgeData(15));
        ageTree.add(new AgeData(10));
        print("Initial tree:");
        print(ageTree.toString());
        print("Removed AgeData(10):");
        ageTree.remove(new AgeData(10));
        print(ageTree.toString());
        print("Removed AgeData(10) again:");
        ageTree.remove(new AgeData(10));
        print(ageTree.toString());
        print("Removed AgeData(20):");
        ageTree.remove(new AgeData(20));
        print(ageTree.toString());
    }

    public static void t_olderYoungerData() {
        print("Older/Younger AgeData counting: ");
        AgeSearchTree ageTree = new AgeSearchTree();
        ageTree.add(new AgeData(10));
        ageTree.add(new AgeData(20));
        ageTree.add(new AgeData(5));
        ageTree.add(new AgeData(15));
        ageTree.add(new AgeData(10));
        print("Initial tree:");
        print(ageTree.toString());
        print("olderThan(5): " + ageTree.olderThan(5));
        print("olderThan(20): " + ageTree.olderThan(20));
        print("olderThan(10): " + ageTree.olderThan(10));
        print("youngerThan(5): " + ageTree.youngerThan(5));
        print("youngerThan(20): " + ageTree.youngerThan(20));
        print("youngerThan(10): " + ageTree.youngerThan(10));
        print("olderThan(0): " + ageTree.olderThan(0));
        print("youngerThan(500): " + ageTree.youngerThan(500));
    }

    public static void t_find() {
        print("Finding AgeData: ");
        AgeSearchTree ageTree = new AgeSearchTree();
        ageTree.add(new AgeData(10));
        ageTree.add(new AgeData(20));
        ageTree.add(new AgeData(5));
        ageTree.add(new AgeData(15));
        ageTree.add(new AgeData(10));
        print("Initial tree:");
        print(ageTree.toString());
        print("Trying to find AgeData(15): ");
        print(ageTree.find(new AgeData(15)).toString());
    }
}