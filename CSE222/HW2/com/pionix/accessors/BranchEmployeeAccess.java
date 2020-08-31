package com.pionix.accessors;

import com.pionix.controllers.*;

/**
 * BranchEmployeeAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>BranchEmployee</code>
 */
public class BranchEmployeeAccess extends UserAccess{
    /**
     * BranchEmployee has access to <code>Customer Model<code/>
     */
    public CustomerController customerController = super.customerController;
    /**
     * BranchEmployee has access to <code>Shipment Model<code/>
     */
    public ShipmentController shipmentController = super.shipmentController;
}
