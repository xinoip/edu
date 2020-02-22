/**
 * <h1> GTUIterator </h1>
 * 
 * Iterator for GTUContainers
 */
public interface GTUIterator<T> {
	
	/**
	 * Next value of iterator
	 * 
	 * @return Generic value
	 */
	public T next();

	/**
	 * Is there a next value after iterator?
	 * 
	 * @return boolean result
	 */
	public boolean hasNext();

	/**
	 * Return current position of iterator
	 * 
	 * @return int position of iterator
	 */
	public int getPos();
}
