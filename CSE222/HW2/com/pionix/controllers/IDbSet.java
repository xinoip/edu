package com.pionix.controllers;

/**
 * A DbSet is like a table in SQL
 *
 * It should hold some kind of model
 * It should have basic operations like
 * get, push, delete, length
 *
 * This interface is for future DbSets
 *
 * @param <T> data type
 */
public interface IDbSet<T> {
    /**
     * Get the data from set with key
     *
     * @param i ket
     * @return data with key
     */
    T get(int i);

    /**
     * Add data to set
     *
     * @param data new data
     */
    void push(T data);

    /**
     * Delete data from set with key
     *
     * @param index key
     * @return success status
     */
    boolean delete(int index);

    /**
     * Size
     *
     * @return size
     */
    int length();
}
