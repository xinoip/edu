package com.pionix;

/**
 * AdministratorAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class AdministratorAccess {
    public AdministratorController administratorController;
    public BranchController branchController;
    public BranchEmployeeController branchEmployeeController;
    public CustomerController customerController;
    public ShipmentController shipmentController;
    public TransportationPersonnelController transportationPersonnelController;

    public AdministratorAccess() {
        administratorController = Database.administratorController;
        branchController = Database.branchController;
        branchEmployeeController = Database.branchEmployeeController;
        customerController = Database.customerController;
        shipmentController = Database.shipmentController;
        transportationPersonnelController = Database.transportationPersonnelController;
    }
}
