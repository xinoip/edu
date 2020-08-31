package com.pionix;

/**
 * This role has access to only checking a shipment
 * with trackingNumber
 */
public class Customer extends PersonRole {
    public final static CustomerAccess access = new CustomerAccess();

    public Customer(String username) {
        super(username);
    }

    @Override
    public String toString() {
        return "Customer name: " + username;
    }
}
