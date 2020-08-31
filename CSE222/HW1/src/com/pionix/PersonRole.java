package com.pionix;

/**
 * PersonRole is the root of the every role for a human.
 *
 */
public class PersonRole {
    protected final String username;

    public PersonRole(String username) {
        this.username = username;
    }

    /**
     * Gets the unique username of the person.
     *
     * @return the username of person
     */
    public String getUsername() {
        return username;
    }
}
