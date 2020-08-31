package com.pionix.controllers;

import com.pionix.models.*;

/**
 * Base controller for available users of the system
 *
 * Every user has a username, so we have this basic operations like
 * get and delete
 *
 * For creation it is different with every user
 * Customer can be created with just a name
 * But BranchEmployee can't, it needs also an available branch
 *
 * This controller creates new tables for given type value
 *
 * @param <T> Users type
 */
public abstract class UserController<T extends User> extends DbController<T> {
    /**
     * Get the index of the user inside the database
     *
     * @param username to search
     * @return index of the given username, -1 if not found
     */
    private int getIndexByUsername(String username) {
        for (int i = 0; i < size(); i++) {
            T user = getByIndex(i);

            if(user.getUsername().equals(username)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Get the user with given username
     *
     * @param username to search
     * @return found user with username or null
     */
    public T getByUsername(String username) {
        int index = getIndexByUsername(username);

        if(index == -1)
            return null;

        return getByIndex(index);
    }

    /**
     * Delete user with the given username
     *
     * @param name to search
     * @return true if deleted, false if not found
     */
    public boolean deleteByUsername(String name) {
        int index = getIndexByUsername(name);

        if(index == -1)
            return false;

        deleteByIndex(index);

        return true;
    }
}
