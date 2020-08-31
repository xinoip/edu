package com.pionix;

/**
 * DbController is the base Controller for any data type
 * Construct objects from models and store them in Database
 *
 * @param <T> type of the stored data
 */
public abstract class DbController<T> {
    private DbArray<T> dbArray;

    public DbController() {
        dbArray = new DbArray<>();
    }

    /**
     * Get by index from database
     *
     * @param index index of object
     * @return object at index
     */
    public T getByIndex(int index) {
        return dbArray.get(index);
    }

    /**
     * Delete by index from database
     *
     * @param index of object to delete
     * @return success of deletion
     */
    public boolean deleteByIndex(int index) {
        return dbArray.delete(index);
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
        dbArray.push(value);
    }

    /**
     * Size of the current object-set
     *
     * @return size
     */
    public int size() {
        return dbArray.length();
    }

    /**
     * Print all of the objects in database
     */
    public void print() {
        for(int i = 0; i < size(); i++) {
            System.out.println(getByIndex(i));
        }
    }
}
