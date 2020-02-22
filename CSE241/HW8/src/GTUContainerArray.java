import java.lang.reflect.Array;

/**
 * <h1>GTUContainerArray</h1>
 * 
 * For container types that represents data with arrays
 */
public abstract class GTUContainerArray<T> extends GTUContainer<T> {
	protected Class<T[]> _type;
	protected T[] _data;
	protected int _cap;
	protected int _size;

	/**
	 * Set initials of the container
	 * Set cap to 3
	 * 
	 * @param type type of the elements of container
	 */
	public GTUContainerArray(Class<T[]> type) {
		_type = type;
		_cap = 3;
		_size = 0;
		_data = type.cast(Array.newInstance(type.getComponentType(), _cap));
	}
	
	public abstract void insert(T obj) throws IllegalArgumentException;

	@Override
	public boolean empty() {
		return _size == 0;
	}

	@Override
	public int size() {
		return _size;
	}

	@Override
	public int max_size() {
		return _cap;
	}

	@Override
	public void clear() {
		_size = 0;
		_cap = 3;
	}

	@Override
	public void erase(T obj) {
		boolean found = false;
		GTUIterator<T> itr = iterator();
		while (itr.hasNext()) {
			T val = itr.next();
			if (val.equals(obj)) {
				found = true;
				break;
			}
		}
		if (found) {
			for (int i = itr.getPos(); i < _size; i++)
				_data[i - 1] = _data[i];
			_size--;
		} else {
			System.out.println("OBJECT TO ERASE NOT FOUND!");
		}
	}

	@Override
	public GTUIterator<T> iterator() {
		return new GTUContainerArrayIterator();
	}

	@Override
	public boolean contains(Object o) {
		boolean found = false;
		GTUIterator<T> iter = iterator();
		while (iter.hasNext()) {
			T val = iter.next();
			if (val.equals(o)) {
				found = true;
				break;
			}
		}
		return found;
	}
	
	/**
	 * <h1> GTUContainerArrayIterator </h1>
	 * 
	 * GTUIterator for containers that represents data as arrays
	 */
	public class GTUContainerArrayIterator implements GTUIterator<T> {
		private int pos = 0;

		@Override
		public boolean hasNext() {
			return pos < _size;
		}

		@Override
		public T next() {
			return _data[pos++];
		}

		@Override
		public int getPos() {
			return pos;
		}

	}

}
