package com.pionix;

/**
 * CustomerAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class CustomerAccess {
    public ShipmentController shipmentController;

    public CustomerAccess() {
        shipmentController = Database.shipmentController;
    }
}
