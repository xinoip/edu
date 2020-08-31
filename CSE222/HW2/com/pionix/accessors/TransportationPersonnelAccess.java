package com.pionix.accessors;

import com.pionix.controllers.*;

/**
 * TransportationPersonnelAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class TransportationPersonnelAccess extends UserAccess {
    /**
     * TransportationPersonnel has access to only delivering shipments
     */
    public ShipmentController shipmentController = super.shipmentController;
}
