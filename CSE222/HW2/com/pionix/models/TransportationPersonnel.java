package com.pionix.models;

import com.pionix.accessors.*;

/**
 * This role has access to only delivering a shipment
 */
public class TransportationPersonnel extends User {
    /**
     * Users access object for user restricted actions
     */
    public final TransportationPersonnelAccess access = new TransportationPersonnelAccess();

    /**
     * New TransportationPersonnel with username
     *
     * @param username customer name
     */
    public TransportationPersonnel(String username) {
        super(username);
    }

    @Override
    public String toString() {
        return "Transportation Personnel name: " + username;
    }
}
