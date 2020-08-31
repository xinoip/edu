package com.pionix;

/**
 * Administrator role has access to everything.
 *
 */
public class Administrator extends PersonRole {
    /**
     * Dependency Injection for admin access
     */
    public final static AdministratorAccess access = new AdministratorAccess();

    public Administrator(String username) {
        super(username);
    }
}
