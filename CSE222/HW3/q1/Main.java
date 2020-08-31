import java.util.Iterator;
import java.util.ListIterator;

public class Main {

    public static void main(String[] args) {
        testAdd();
        testRemoveByObject();
        testRemoveByIndex();
        testIteratorPrintForwards();
        testIteratorPrintBackwards();
        testClearList();
        testRemoveNodeDemo();
        testAddToAnyIndex();
        testAddToAnyIndexAndExhaustArray();
    }

    public static void testAdd() {
        print("Test: Add object to list");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        System.out.println(myList);
        print("End of test\n\n");
    }

    public static void testRemoveByObject() {
        print("Test: Remove object from list");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        print("Initial list:");
        print(myList.toString());

        myList.remove(Integer.valueOf(11));
        myList.remove(Integer.valueOf(12));
        myList.remove(Integer.valueOf(16));
        myList.remove(Integer.valueOf(5));

        print("Removed elements 11-12-16-5:");
        print(myList.toString());

        print("End of test\n\n");
    }

    public static void testRemoveByIndex() {
        print("Test: Remove object from list by index");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        print("Initial list:");
        print(myList.toString());

        for(int i = 11; i <= 20; i++) {
            myList.remove(i);
        }
        print("Removed elements from index 11 to 20:");
        print(myList.toString());

        print("End of test\n\n");
    }

    public static void testIteratorPrintForwards() {
        print("Test: Print list forwards with iterator");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        Iterator<Integer> iteratorFoo = myList.iterator();
        while (true) {
            if(!iteratorFoo.hasNext()){
                System.out.print(iteratorFoo.next().toString() + " ");
                break;
            }
            System.out.print(iteratorFoo.next().toString() + " ");
        }
        System.out.println();
        print("End of test\n\n");
    }

    public static void testIteratorPrintBackwards() {
        print("Test: Print list backwards from given index with iterator");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        ListIterator<Integer> listIterator = myList.listIterator(11);
        while (true) {
            if(!listIterator.hasPrevious()){
                System.out.print(listIterator.previous().toString() + " ");
                break;
            }
            System.out.print(listIterator.previous().toString() + " ");
        }
        System.out.println();
        print("End of test\n\n");
    }

    public static void testClearList() {
        print("Test: Clear list");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        myList.clear();

        System.out.println(myList);
        print("End of test\n\n");
    }

    public static void testRemoveNodeDemo() {
        print("Test: When an array in node is fully cleared, remove that node");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        print("Initial list:");
        print(myList.toString());

        for(int i = 11; i <= 20; i++) {
            myList.remove(Integer.valueOf(i));
        }

        print("Removed middle node by removing all elements inside the array of it");
        System.out.println(myList);
        print("End of test\n\n");
    }

    public static void testAddToAnyIndex() {
        print("Test: When adding to an array that has empty space, just insert and shift");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        myList.remove(Integer.valueOf(15));
        myList.remove(Integer.valueOf(16));
        print("Initial list:");
        print(myList.toString());

        myList.add(15, 999);

        print("Insert 999 to index 15, it will shift the array forward because array contains empty space.");
        System.out.println(myList);
        print("End of test\n\n");
    }

    public static void testAddToAnyIndexAndExhaustArray() {
        print("Test: When adding to a full array, new node is inserted");
        LinkedArrayList<Integer> myList = new LinkedArrayList<>();

        for(int i = 1; i < 30; i++) {
            myList.add(i);
        }

        print("Initial list:");
        print(myList.toString());

        myList.add(15, 999);

        print("Insert 999 to index 15, it will exhaust the array, shift it and insert new node.");
        System.out.println(myList);
        print("End of test\n\n");

    }

    public static void print(String str) {
        System.out.println(str);
    }

}
