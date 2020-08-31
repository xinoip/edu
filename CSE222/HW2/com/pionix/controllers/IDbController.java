package com.pionix.controllers;

/**
 * Interface for DbControllers
 *
 * A DbController should have basic operations like
 * get, delete, update, create, size, listing
 *
 * This is the interface for them
 *
 * @param <T> data type to be controlled
 */
public interface IDbController<T> {
    /**
     * Get the data by index key
     *
     * @param index data key
     * @return data with the key
     */
    T getByIndex(int index);

    /**
     * Delete the data by index key
     *
     * @param index data key
     * @return success status
     */
    boolean deleteByIndex(int index);

    /**
     * Update the data with index key
     *
     * @param index data key
     * @param updatedValue new value for data
     * @return success status
     */
    boolean updateByIndex(int index, T updatedValue);

    /**
     * Create new data
     *
     * @param value new data
     */
    void create(T value);

    /**
     * Current size of data set
     *
     * @return size
     */
    int size();

    /**
     * Print the data set with base toString
     *
     */
    void print();

    /**
     * Clear the data set
     *
     */
    void clear();
}
