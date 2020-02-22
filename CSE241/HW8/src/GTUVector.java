import java.lang.reflect.Array;

/**
 * <h1>GTUVector</h1>
 * 
 * Vector as GTUContainerArray
 */
public class GTUVector<T> extends GTUContainerArray<T> {

	public GTUVector(Class<T[]> type) {
		super(type);
	}

	@Override
	public void insert(T obj) throws IllegalArgumentException {
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
	}

}
