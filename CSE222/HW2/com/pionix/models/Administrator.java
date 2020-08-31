package com.pionix.models;

import com.pionix.accessors.*;

/**
 * Administrator role has access to everything.
 *
 */
public class Administrator extends User {
    /**
     * Dependency Injection for admin access
     */
    public final AdministratorAccess access = new AdministratorAccess();

    /**
     * Pass the username to super constructor
     */
    public Administrator(String username) {
        super(username);
    }
}
