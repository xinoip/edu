package com.pionix.controllers;

import com.pionix.models.*;

/**
 * CustomerController is the <code>DbController</code> for the Customer data model
 */
public class CustomerController extends UserController<Customer> {
    /**
     * Create new Customer object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean create(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Customer!");
            return false;
        }

        Customer customer = new Customer(username);

        create(customer);

        return true;
    }
}
