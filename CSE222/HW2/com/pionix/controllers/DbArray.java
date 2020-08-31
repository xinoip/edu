package com.pionix.controllers;

/**
 * Custom dynamic array implementation for <code>IDbSet</code>
 * It can dynamically add and remove items
 * Stored as Array
 *
 * @param <T> data type for <code>IDbSet</code>
 */
public class DbArray<T> implements IDbSet<T> {
    private Object[] _dataArray;
    private int _size;
    private int _cap;

    public DbArray() {
        _size = 0;
        _cap = 10;
        _dataArray = new Object[_cap];
    }

    /**
     * Get data from index
     *
     * @param i index
     * @return data at index
     */
    public T get(int i) {
        @SuppressWarnings("unchecked")
        final T data = (T) _dataArray[i];
        return data;
    }

    /**
     * Push data to array
     *
     * @param data new data to be added
     */
    public void push(T data) {
        if(_size >= _cap) {
            _cap *= 2;
            Object[] copyArr = new Object[_cap];

            for(int i = 0; i < _size; i++) {
                T currentData = get(i);
                copyArr[i] = currentData;
            }
            _dataArray = copyArr;
        }
        _dataArray[_size++] = data;
    }

    /**
     * Delete data at index
     *
     * @param index index of data to delete
     * @return delete success, if index is not valid returns false
     */
    public boolean delete(int index) {
        boolean isDeleted = false;
        Object[] copyArr = new Object[_cap];

        int copyArrIndex = 0;
        for(int i = 0; i < _size; i++) {
            if(index != i) {
                T currentData = get(i);
                copyArr[copyArrIndex++] = currentData;
            } else {
                isDeleted = true;
            }
        }

        _dataArray = copyArr;
        _size--;
        return isDeleted;
    }

    /**
     * Current length of array
     * @return length
     */
    public int length() {
        return _size;
    }
}
