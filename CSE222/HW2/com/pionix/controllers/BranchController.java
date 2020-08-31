package com.pionix.controllers;

import com.pionix.models.*;

/**
 * BranchController is the <code>DbController</code> for the Branch data model
 */
public class BranchController extends DbController<Branch> {
    /**
     * Get the index of the branch inside the database
     *
     * @param name to search
     * @return index of the branch with name, -1 if not found
     */
    private int getIndexByName(String name) {
        for (int i = 0; i < size(); i++) {
            Branch branch = getByIndex(i);

            if(branch.getName().equals(name)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Get the branch with given name
     *
     * @param name to search
     * @return found branch with name or null
     */
    public Branch getByName(String name) {
        int index = getIndexByName(name);

        if(index == -1)
            return null;

        return getByIndex(index);
    }

    /**
     * Delete branch with the given name
     *
     * @param name to search
     * @return true if deleted, false if not found
     */
    public boolean deleteByName(String name) {
        int index = getIndexByName(name);

        if(index == -1) {
            System.out.println("No such branch found with the given name!");
            return false;
        }


        deleteByIndex(index);

        return true;
    }

    /**
     * Create new Branch object from the model, in database
     *
     * @param branchName new branches name
     * @return true if successful, false if branchName already exists in database
     */
    public boolean createNewBranch(String branchName) {
        if(getByName(branchName) != null) {
            System.out.println("Branch name duplicate when creating new branch!");
            return false;
        }

        Branch branch = new Branch(branchName);

        create(branch);

        return true;
    }
}
