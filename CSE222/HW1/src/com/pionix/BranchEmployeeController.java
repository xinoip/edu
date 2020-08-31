package com.pionix;

/**
 * BranchEmployeeController is the <code>DbController</code> for the BranchEmployee data model
 */
public class BranchEmployeeController extends DbController<BranchEmployee> {
    private BranchController branchController;

    /**
     * Inject dependency <code>BranchController</code>
     *
     * @param branchController to inject dependency
     */
    public BranchEmployeeController(BranchController branchController) {
        this.branchController = branchController;
    }

    /**
     * Get the index of the user inside the database
     *
     * @param username to search
     * @return index of the given username, -1 if not found
     */
    private int getIndexByUsername(String username) {
        for (int i = 0; i < size(); i++) {
            BranchEmployee employee = getByIndex(i);

            if(employee.getUsername().equals(username)) {
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
    public BranchEmployee getByUsername(String username) {
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
     * Create new BranchEmployee object from the model in database
     *
     * @param username new users name
     * @return true if successful, false if username already exists in database
     */
    public boolean createNewBranchEmployee(String username, String branchName) {
        if(getByUsername(username) != null) {
            System.out.println("Username duplicate when creating new Branch Employee!");
            return false;
        }

        Branch branch = branchController.getByName(branchName);
        if(branch == null) {
            System.out.println("Branch not found when creating new Branch Employee!");
            return false;
        }

        BranchEmployee employee = new BranchEmployee(username, branch);

        create(employee);

        return true;
    }
}
