package com.pionix;

/**
 * This role has access to only delivering a shipment
 */
public class TransportationPersonnel extends PersonRole {
    public final static TransportationPersonnelAccess access = new TransportationPersonnelAccess();

    public TransportationPersonnel(String username) {
        super(username);
    }

    @Override
    public String toString() {
        return "Transportation Personnel name: " + username;
    }
}
