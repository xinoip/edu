package com.pionix.models;

import com.pionix.accessors.*;

/**
 * This role has access to only checking a shipment
 * with trackingNumber
 */
public class Customer extends User {
    /**
     * Users access object for user restricted actions
     */
    public final CustomerAccess access = new CustomerAccess();

    /**
     * New Customer with username
     *
     * @param username customer name
     */
    public Customer(String username) {
        super(username);
    }

    @Override
    public String toString() {
        return "Customer name: " + username;
    }
}
