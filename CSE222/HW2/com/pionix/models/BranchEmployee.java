package com.pionix.models;

import com.pionix.accessors.*;

/**
 * This user has access to only branch specific things like
 * shipment and customer management
 */
public class BranchEmployee extends User {
    /**
     * Users access object for user restricted actions
     */
    public final BranchEmployeeAccess access = new BranchEmployeeAccess();

    /**
     * Employees working branch
     */
    private final Branch branch;

    /**
     * New BranchEmployee with username and existing branch
     *
     * @param username employee name
     * @param branch working branch
     */
    public BranchEmployee(String username, Branch branch) {
        super(username);
        this.branch = branch;
    }

    @Override
    public String toString() {
        return "Branch Employee name: " + username;
    }

    /**
     * Get the branch that employee is working in
     *
     * @return Employees working branch
     */
    public Branch getBranch() {
        return branch;
    }
}
