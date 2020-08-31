package com.pionix.accessors;

import com.pionix.controllers.*;

/**
 * CustomerAccess is a class for DependencyInjection
 *
 * It is used for giving access to <code>PersonRole</code>
 */
public class CustomerAccess extends UserAccess{
    /**
     * Customer has access to only viewing shipments info
     */
    public ShipmentController shipmentController = super.shipmentController;
}
