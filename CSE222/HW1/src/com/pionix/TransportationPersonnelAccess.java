package com.pionix;

/**
 * TransportationPersonnelAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class TransportationPersonnelAccess {
    public ShipmentController shipmentController;

    public TransportationPersonnelAccess() {
        shipmentController = Database.shipmentController;
    }
}
