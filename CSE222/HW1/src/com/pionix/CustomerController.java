package com.pionix;

/**
 * BranchEmployeeController is the <code>DbController</code> for the BranchEmployee data model
 */
public class CustomerController extends DbController<Customer> {
    /**
     * Get the index of the user inside the database
     *
     * @param username to search
     * @return index of the given username, -1 if not found
     */
    private int getIndexByUsername(String username) {
        for (int i = 0; i < size(); i++) {
            Customer customer = getByIndex(i);

            if(customer.getUsername().equals(username)) {
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
    public Customer getByUsername(String username) {
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
     * Create new Customer object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean createNewCustomer(String username) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Customer!");
            return false;
        }

        Customer customer = new Customer(username);

        create(customer);

        return true;
    }
}
