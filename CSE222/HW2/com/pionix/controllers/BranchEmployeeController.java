package com.pionix.controllers;

import com.pionix.models.*;

/**
 * BranchEmployeeController is the <code>DbController</code> for the BranchEmployee data model
 */
public class BranchEmployeeController extends UserController<BranchEmployee> {
    /**
     * Needed for checking available branches when creating new branch employee
     */
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
     * Create new BranchEmployee from model in Database
     *
     * @param username users name
     * @param branchName users branches name
     * @return success status
     */
    public boolean create(String username, String branchName) {
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
