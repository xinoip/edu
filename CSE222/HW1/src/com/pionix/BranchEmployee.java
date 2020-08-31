package com.pionix;

/**
 * This role has access to only branch specific things like
 * shipment and customer management
 */
public class BranchEmployee extends PersonRole{
    public final static BranchEmployeeAccess access = new BranchEmployeeAccess();
    private final Branch branch;

    public BranchEmployee(String username, Branch branch) {
        super(username);
        this.branch = branch;
    }

    @Override
    public String toString() {
        return "Branch Employee name: " + username;
    }

    public Branch getBranch() {
        return branch;
    }
}
