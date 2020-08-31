package com.pionix.controllers;

import com.pionix.models.*;

/**
 * TransportationPersonnelController is the <code>DbController</code> for the TransportationPersonnel data model
 */
public class TransportationPersonnelController extends UserController<TransportationPersonnel> {
    /**
     * Create new TransportationPersonnel object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean create(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Transportation Personnel!");
            return false;
        }

        TransportationPersonnel personnel = new TransportationPersonnel(username);

        create(personnel);

        return true;
    }
}
