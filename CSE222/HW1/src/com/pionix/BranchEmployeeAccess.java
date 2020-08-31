package com.pionix;

/**
 * BranchEmployeeAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class BranchEmployeeAccess {
    public CustomerController customerController;
    public ShipmentController shipmentController;

    public BranchEmployeeAccess() {
        customerController = Database.customerController;
        shipmentController = Database.shipmentController;
    }
}
