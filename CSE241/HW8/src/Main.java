
/**
 * <h1>Homework 8</h1>
 * <p>
 * Container class hierarchy for CSE241 at GTU
 * </p>
 *
 * @author Buğra Eren Yılmaz
 * @version 1.0
 * @since 2020-01-17
 */
public class Main {

	public static void main(String[] args) {
		
		// Creation of containers
		GTUVector<Integer> v = new GTUVector<Integer>(Integer[].class);
	    GTUSet<Integer> set = new GTUSet<Integer>(Integer[].class);

	    // General tests of containers
	    PioTester.testContainer(v, "vector");
	    PioTester.testContainer(set, "set");
	    
	    // Clear containers
	    PioTester.testClearContainer(v, "vector");
	    PioTester.testClearContainer(set, "set");
	}

}
