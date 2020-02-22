
/**
 * <h1>PioTester</h1>
 * 
 * Tests for GTUContainers
 */
public class PioTester {

	/**
	 * Tests
	 * <ol>
	 * <li>Show getters<li>
	 * <li>Insert values and catch exceptions<li>
	 * <li>Printing<li>
	 * <li>Erase values<li>
	 * <li>Printing<li>
	 * <li>Test contains method<li>
	 * <li>Show getters<li>
	 * </ol>
	 *
	 * @param GTUContainer to be tested
	 * @param String the test name
	 */
	public static void testContainer(GTUContainer<Integer> v, String name) {
		System.out.print("==================================\n");
		System.out.print("Start of " + name + " test!\n\n");

		System.out.print("max_size(): " + v.max_size() + "\n");
		System.out.print("size(): " + v.size() + "\n");
		System.out.print("empty(): " + v.empty() + "\n-\n");

		System.out.print("Inserting values to " + name + "... \n");
		try {
			v.insert(5);
			v.insert(6);
			v.insert(7);
			v.insert(8);
			v.insert(3);
			v.insert(16);
			v.insert(321);
			v.insert(245);
			v.insert(-15);
			v.insert(32);
			v.insert(27);
			v.insert(56);
			v.insert(245);
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.print("Insertion done! \n-\n");

		System.out.print("Printing " + name + "... \n");
		printContainer(v);
		System.out.print("Printing done! \n-\n");
		
		System.out.print("Erasing 245 and 27...\n");
		v.erase(245);
		v.erase(27);
		System.out.print("Erasing done\n");
		
		System.out.print("Printing " + name + "... \n");
		printContainer(v);
		System.out.print("Printing done! \n-\n");

		System.out.println("Has value of 27: " + v.contains(27));
		System.out.println("Has value of 56: " + v.contains(56));
		
		System.out.print("max_size(): " + v.max_size() + "\n");
		System.out.print("size(): " + v.size() + "\n");
		System.out.print("empty(): " + v.empty() + "\n-\n");

		System.out.print("\nEnd of " + name + " test!\n");
		System.out.print("==================================\n");
	}

	/**
	 * Print the contents of given GTUContainer
	 * 
	 * @param GTUContainer
	 */
	public static void printContainer(GTUContainer<Integer> container) {
		GTUIterator<Integer> itr = container.iterator();
		while (itr.hasNext()) {
			System.out.print(itr.next() + " ");
		}
		System.out.println();
	}

	/**
	 * Clear the given container and print results
	 * 
	 * @param GTUContainer
	 * @param String testName
	 */
	public static void testClearContainer(GTUContainer<Integer> v, String name) {
		System.out.print("Clearing " + name + "... \n");
		v.clear();
		System.out.print("Clear done! \n-\n");

		System.out.print("max_size(): " + v.max_size() + "\n");
		System.out.print("size(): " + v.size() + "\n");
		System.out.print("empty(): " + v.empty() + "\n-\n");

		System.out.print("Printing " + name + "... \n");
		printContainer(v);
		System.out.print("Printing done! \n-\n");
	}

}
