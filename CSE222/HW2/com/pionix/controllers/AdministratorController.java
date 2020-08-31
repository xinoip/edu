package com.pionix.controllers;

import com.pionix.models.*;

/**
 * AdministratorController is the <code>DbController</code> for the <code>Administrator Model</code>
 */
public class AdministratorController extends UserController<Administrator> {
    /**
     * Create new Administrator object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean create(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Administrator!");
            return false;
        }

        Administrator admin = new Administrator(username);

        create(admin);

        return true;
    }
}
