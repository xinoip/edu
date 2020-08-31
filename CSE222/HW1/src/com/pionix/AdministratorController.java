package com.pionix;

/**
 * AdministratorController is the <code>DbController</code> for the Administrator data model
 */
public class AdministratorController extends DbController<Administrator> {
    /**
     * Get the index of the user inside the database
     *
     * @param username to search
     * @return index of the given username, -1 if not found
     */
    private int getIndexByUsername(String username) {
        for (int i = 0; i < size(); i++) {
            Administrator admin = getByIndex(i);

            if(admin.getUsername().equals(username)) {
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
    public Administrator getByUsername(String username) {
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
     * Create new Administrator object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean createNewAdministrator(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Administrator!");
            return false;
        }

        Administrator admin = new Administrator(username);

        create(admin);

        return true;
    }
}
