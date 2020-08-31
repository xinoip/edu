import java.util.Iterator;
import java.util.LinkedList;

/**
 * Tests for custom deque class: MyDeque
 */
public class DequeTests {

    private MyDeque<Integer> deque;

    DequeTests() {
        deque = new MyDeque<Integer>();
    }

    /**
     * Prints status of deque and removed items
     * @param testName printing for testName
     */
    private void dequeStatus(String testName) {
        System.out.println("Results " + testName + ":");
        deque.printDequeStatus();
        deque.printRemovedStatus();
        System.out.println();
    }

    /**
     * General info for tests
     *
     * @param name test name
     * @param description test description
     * @param dequeStatus expected deque status after test
     * @param removedStatus expected removed status after test
     */
    private void testInfo(String name, String description, String dequeStatus, String removedStatus) {
        System.out.println("Test " + name + ":\n" + "" + "" +
                "- " + description +
                "\n- Expected DequeStatus: " + dequeStatus + "" +
                "\n- Expected RemovedStatus: " + removedStatus);
    }

    /**
     * Starts tests
     */
    public void doTests() {
        t_addFirst();
        t_clear();
        t_addLast();
        t_removeFirst();
        t_removeLast();
        t_removeFirstOccurrence();
        t_removeLastOccurrence();
        t_contains();
        t_size();
        t_iterator();
        t_descendingIterator();
        t_addAll();
        t_removeAll();
    }

    /**
     * Testing addFirst
     */
    public void t_addFirst() {
        testInfo("addFirst", "Trying to addFirst: 1,2,3,4","[4,3,2,1]", "[]");
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);
        deque.addFirst(4);
        dequeStatus("addFirst");
    }

    /**
     * Testing addLast
     */
    public void t_addLast() {
        testInfo("addLast", "Trying to addLast: 7,8,9. Showing that it does not create new nodes instead uses removed nodes.","[7,8,9]", "[4]");
        System.out.println("Adding 7 to end...");
        deque.addLast(7);
        deque.printDequeStatus();
        deque.printRemovedStatus();
        System.out.println("Adding 8 to end...");
        deque.addLast(8);
        deque.printDequeStatus();
        deque.printRemovedStatus();
        System.out.println("Adding 9 to end...");
        deque.addLast(9);
        dequeStatus("addLast");
    }

    /**
     * Testing clear
     */
    public void t_clear() {
        testInfo("clear", "Trying to clear deque, removed list will be populated.","[]", "[1,2,3,4]");
        deque.clear();
        dequeStatus("clear");
    }

    /**
     * Testing removeFirst
     */
    public void t_removeFirst() {
        testInfo("removeFirst", "Trying to removeFirst element.","[8,9]", "[4,7]");
        deque.removeFirst();
        dequeStatus("removeFirst");
    }

    /**
     * Testing removeLast
     */
    public void t_removeLast() {
        testInfo("removeLast", "Trying to removeLast element.","[8]", "[4,7,9]");
        deque.removeLast();
        dequeStatus("removeLast");
    }

    /**
     * Testing removeFirstOccurrence
     */
    public void t_removeFirstOccurrence() {
        System.out.println("Populated the deque with 1,2,3,4,3,1,1 for next test!");
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);
        deque.addFirst(4);
        deque.addFirst(3);
        deque.addFirst(1);
        deque.addFirst(1);
        dequeStatus("Populated");
        testInfo("removeFirstOccurrence", "Trying to removeFirstOccurrence element 8.","[1,1,3,4,3,2,1]", "[8]");
        deque.removeFirstOccurrence(8);
        dequeStatus("removeFirstOccurrence");
    }

    /**
     * Testing removeLastOccurrence
     */
    public void t_removeLastOccurrence() {
        testInfo("removeLastOccurrence", "Trying to removeLastOccurrence element 3.","[1,1,3,4,2,1]", "[8,3]");
        deque.removeLastOccurrence(3);
        dequeStatus("removeLastOccurrence");
    }

    /**
     * Testing contains
     */
    public void t_contains() {
        testInfo("contains", "Trying to find element 2 is existing or not. Expecting true.","[1,1,3,4,2,1]", "[8,3]");
        boolean found = deque.contains(2);
        System.out.println("Contains element 2: " + found);
        dequeStatus("contains");
    }

    /**
     * Testing size
     */
    public void t_size() {
        testInfo("size", "Trying to get size. Expecting 6.","[1,1,3,4,2,1]", "[8,3]");
        int size = deque.size();
        System.out.println("Size of deque: " + size);
        dequeStatus("size");
    }

    /**
     * Testing iterator
     */
    public void t_iterator() {
        testInfo("iterator", "Trying to print deque with iterator.","[1,1,3,4,2,1]", "[8,3]");
        Iterator<Integer> itr = deque.iterator();
        while(itr.hasNext()) {
            System.out.print("itr(" + itr.next() + ") ");
        }
        System.out.println();
        dequeStatus("iterator");
    }

    /**
     * Testing descendingIterator
     */
    public void t_descendingIterator() {
        testInfo("descendingIterator", "Trying to print deque in reverse with descendingIterator.","[1,1,3,4,2,1]", "[8,3]");
        AbstractNodeList<Integer>.NodeIterator itr = (AbstractNodeList<Integer>.NodeIterator) deque.descendingIterator();
        while(itr.hasPrevious()) {
            System.out.print("itr(" + itr.previous().data + ") ");
        }
        System.out.println();
        dequeStatus("descendingIterator");
    }

    /**
     * Testing AbstractCollection validity with addAll
     */
    public void t_addAll() {
        testInfo("addAll", "Trying to add another collection with items 111,211,311.","[1,1,3,4,2,1,111,211,311]", "[]");
        LinkedList<Integer> foo = new LinkedList<>();
        foo.add(111);
        foo.add(211);
        foo.add(311);
        deque.addAll(foo);
        dequeStatus("addAll");
    }

    /**
     * Testing AbstractCollection validity with removeAll
     */
    public void t_removeAll() {
        testInfo("removeAll", "Trying to remove items by removeAll: 3,2.","[1,1,4,1,111,211,311]", "[3,4,2]");
        LinkedList<Integer> foo = new LinkedList<>();
        foo.add(3);
        foo.add(2);
        deque.removeAll(foo);
        deque.printDequeStatus();
    }
}
