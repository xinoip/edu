
/**
 * <h1>GTUContainer</h1>
 */
public abstract class GTUContainer<T> {

	/**
	 * Is container empty?
	 * 
	 * @return boolean value result
	 */
	public abstract boolean empty();

	/**
	 * Return size of container.
	 * 
	 * @return integer
	 */
	public abstract int size();

	/**
	 * Return current capacity of container.
	 * 
	 * @return integer
	 */
	public abstract int max_size();

	/**
	 * Try to insert given object to container It may throw illegal argument
	 * exception
	 * 
	 * @param new object
	 */
	public abstract void insert(T obj) throws IllegalArgumentException;

	/**
	 * Try to find and erase given object from container
	 * 
	 * @param delete object
	 */
	public abstract void erase(T obj);

	/**
	 * Clear all contents of container
	 * 
	 */
	public abstract void clear();

	/**
	 * Return a iterator to beginning of the container
	 * 
	 * @return GTUIterator
	 */
	public abstract GTUIterator<T> iterator();

	/**
	 * Does the container has object o?
	 * 
	 * @return boolean
	 */
	public abstract boolean contains(Object o);

}
