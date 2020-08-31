package com.pionix;

/**
 * TransportationPersonnelController is the <code>DbController</code> for the TransportationPersonnel data model
 */
public class TransportationPersonnelController extends DbController<TransportationPersonnel> {
    /**
     * Get the index of the user inside the database
     *
     * @param username to search
     * @return index of the given username, -1 if not found
     */
    private int getIndexByUsername(String username) {
        for (int i = 0; i < size(); i++) {
            TransportationPersonnel personnel = getByIndex(i);

            if(personnel.getUsername().equals(username)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Get the user with given username
     *
     * @param username to search
     * @return found user with username or null
     */
    public TransportationPersonnel getByUsername(String username) {
        int index = getIndexByUsername(username);

        if(index == -1)
            return null;

        return getByIndex(index);
    }

    /**
     * Delete user with the given username
     *
     * @param name to search
     * @return true if deleted, false if not found
     */
    public boolean deleteByUsername(String name) {
        int index = getIndexByUsername(name);

        if(index == -1)
            return false;

        deleteByIndex(index);

        return true;
    }

    /**
     * Create new TransportationPersonnel object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean createNewTransportationPersonnel(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Transportation Personnel!");
            return false;
        }

        TransportationPersonnel personnel = new TransportationPersonnel(username);

        create(personnel);

        return true;
    }
}
