package com.pionix.accessors;

import com.pionix.controllers.*;

/**
 * AdministratorAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>Administrator User</code>
 */
public class AdministratorAccess extends UserAccess {
    /**
     * Administrator has access to <code>Administrator Model<code/>
     */
    public AdministratorController administratorController = super.administratorController;
    /**
     * Administrator has access to <code>Branch Model<code/>
     */
    public BranchController branchController = super.branchController;
    /**
     * Administrator has access to <code>BranchEmployee Model<code/>
     */
    public BranchEmployeeController branchEmployeeController = super.branchEmployeeController;
    /**
     * Administrator has access to <code>Customer Model<code/>
     */
    public CustomerController customerController = super.customerController;
    /**
     * Administrator has access to <code>Shipment Model<code/>
     */
    public ShipmentController shipmentController = super.shipmentController;
    /**
     * Administrator has access to <code>TransportationPersonnel Model<code/>
     */
    public TransportationPersonnelController transportationPersonnelController = super.transportationPersonnelController;
}
