package com.pionix.accessors;

import com.pionix.controllers.*;
import com.pionix.Database;

/**
 * Hold every possible access to database controllers
 *
 * Overridden in derived access classes to give restrictions to roles
 */
public abstract class UserAccess {
    /**
     * access to <code>Administrator Model<code/>
     */
    protected AdministratorController administratorController;
    /**
     * access to <code>Branch Model<code/>
     */
    protected BranchController branchController;
    /**
     * access to <code>BranchEmployee Model<code/>
     */
    protected BranchEmployeeController branchEmployeeController;
    /**
     * access to <code>Customer Model<code/>
     */
    protected CustomerController customerController;
    /**
     * access to <code>Shipment Model<code/>
     */
    protected ShipmentController shipmentController;
    /**
     * access to <code>TransportationPersonnel Model<code/>
     */
    protected TransportationPersonnelController transportationPersonnelController;

    /**
     * Dependency Inject required <code>DbControllers</code>
     */
    protected UserAccess() {
        administratorController = Database.administratorController;
        branchController = Database.branchController;
        branchEmployeeController = Database.branchEmployeeController;
        customerController = Database.customerController;
        shipmentController = Database.shipmentController;
        transportationPersonnelController = Database.transportationPersonnelController;
    }
}
