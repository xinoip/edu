import java.lang.reflect.Array;

/**
 * <h1>GTUSet</h1>
 * 
 * Set as GTUContainerArray
 */
public class GTUSet<T> extends GTUContainerArray<T> {

	public GTUSet(Class<T[]> type) {
		super(type);
	}

	@Override
	public void insert(T obj) throws IllegalArgumentException {
		boolean found = false;
		GTUIterator<T> itr = iterator();
		while (itr.hasNext()) {
			T curr = itr.next();
			if (curr.equals(obj)) {
				found = true;
				break;
			}
		}
		if (!found) {
			if (_size + 1 >= _cap) {
				// tmp array with new size
				T[] tmp = _type.cast(Array.newInstance(_type.getComponentType(), _cap * 2));

				// copy content to new array
				for (int i = 0; i < _size; i++) {
					tmp[i] = _data[i];
				}

				// increase size
				_data = _type.cast(Array.newInstance(_type.getComponentType(), _cap * 2));

				// copy content back to data
				for (int i = 0; i < _size; i++) {
					_data[i] = tmp[i];
				}

				// increase capacity
				_cap *= 2;

			}

			// insert new object
			_data[_size++] = obj;
		} else {
			throw new IllegalArgumentException("(1801042669) Element is already inside of the set: " + obj);
		}
	}

}
