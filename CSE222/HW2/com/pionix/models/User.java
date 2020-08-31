package com.pionix.models;

/**
 * User is the root of the available users for system.
 */
public class User {
    /**
     * Every user should have a username
     */
    protected final String username;

    /**
     * Base constructor with name
     * @param username username
     */
    public User(String username) {
        this.username = username;
    }

    /**
     * Gets the username of the person .
     *
     * @return the username of person
     */
    public String getUsername() {
        return username;
    }
}
