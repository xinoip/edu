package com.pionix.controllers;

import java.util.ArrayList;

/**
 * ArrayList container implementation for <code>IDbSet</code>
 * Stored as ArrayList
 *
 * @param <T> data type for <code>IDbSet</code>
 */
public class DbArrayList<T> implements IDbSet<T> {
    private ArrayList<T> _dataArray;

    public DbArrayList() {
        _dataArray = new ArrayList<>();
    }

    /**
     * Get data from index
     *
     * @param i index
     * @return data at index
     */
    public T get(int i) {
        return _dataArray.get(i);
    }

    /**
     * Push data to array
     *
     * @param data new data to be added
     */
    public void push(T data) {
        _dataArray.add(data);
    }

    /**
     * Delete data at index
     *
     * @param index index of data to delete
     * @return delete success, if index is not valid returns false
     */
    public boolean delete(int index) {
        _dataArray.remove(index);
        return true;
    }

    /**
     * Current length of array
     * @return length
     */
    public int length() {
        return _dataArray.size();
    }
}
