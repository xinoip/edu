package com.pionix.controllers;

/**
 * DbController is the base Controller for any data type
 * Construct objects from models and store them in Database
 * It has basic operations for any possible Entity like
 * get, delete, create update operations
 *
 * It stores the data as <code>IDbSet</code> implemented as <code>DbArrayList</code>
 *
 * It both controls and stores the data set like a Database table.
 *
 * @param <T> type of the stored data
 */
public abstract class DbController<T> implements IDbController<T> {
    private IDbSet<T> dbSet;

    public DbController() {
        dbSet = new DbArrayList<>();
    }

    /**
     * Get by index from database
     *
     * @param index index of object
     * @return object at index
     */
    public T getByIndex(int index) {
        return dbSet.get(index);
    }

    /**
     * Delete by index from database
     *
     * @param index of object to delete
     * @return success of deletion
     */
    public boolean deleteByIndex(int index) {
        return dbSet.delete(index);
    }

    /**
     * Update by index from database
     *
     * @param index index of object to update
     * @param updatedValue object to replace
     * @return success of update operation
     */
    public boolean updateByIndex(int index, T updatedValue) {
        if(!deleteByIndex(index))
            return false;

        create(updatedValue);

        return true;
    }

    /**
     * Create object at database
     *
     * @param value new object
     */
    public void create(T value) {
        dbSet.push(value);
    }

    /**
     * Size of the current object-set
     *
     * @return size
     */
    public int size() {
        return dbSet.length();
    }

    /**
     * Print all of the objects in database
     */
    public void print() {
        for(int i = 0; i < size(); i++) {
            System.out.println(getByIndex(i));
        }
    }

    public void clear() {
        for(int i = 0; i < size(); i++) {
            deleteByIndex(i);
        }
    }
}
