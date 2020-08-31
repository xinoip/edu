package com.pionix.controllers;

import com.pionix.models.*;

/**
 * ShipmentController is the <code>DbController</code> for the Shipment data model
 */
public class ShipmentController extends DbController<Shipment> {
    /**
     * Dependency needed for getting customer info from db
     *
     * When creating new shipment db should have Sender and Receiver as Customers
     */
    private CustomerController customerController;
    /**
     * Dependency needed for getting the branch info from db
     */
    private BranchController branchController;

    /**
     * Inject dependency <code>BranchController</code>
     * Inject dependency <code>CustomerController</code>
     *
     * @param branchController to inject dependency
     * @param customerController to inject dependency
     */
    public ShipmentController(CustomerController customerController, BranchController branchController) {
        this.customerController = customerController;
        this.branchController = branchController;
    }

    /**
     * Get index of the object from database with trackingNumber
     *
     * @param trackingNumber to search
     * @return index of the object, or -1 if not found
     */
    private int getIndexByTrackingNumber(int trackingNumber) {
        for (int i = 0; i < size(); i++) {
            Shipment shipment = getByIndex(i);

            if(shipment.getTrackingNumber() == trackingNumber) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Get the object from database with trackingNumber
     *
     * @param trackingNumber to search
     * @return found object or null
     */
    public Shipment getByTrackingNumber(int trackingNumber) {
        int index = getIndexByTrackingNumber(trackingNumber);

        if(index == -1)
            return null;

        return getByIndex(index);
    }

    /**
     * Delete the object with the given trackingNumber
     *
     * @param trackingNumber to search
     * @return success of deletion, false if not found
     */
    public boolean deleteByTrackingNumber(int trackingNumber) {
        int index = getIndexByTrackingNumber(trackingNumber);

        if(index == -1)
            return false;

        deleteByIndex(index);

        return true;
    }

    /**
     * Update the object with trackingNumber
     *
     * @param trackingNumber index of the object to update
     * @param updatedValue new object
     * @return success of update, false if not found
     */
    public boolean updateByTrackingNumber(int trackingNumber, Shipment updatedValue) {
        int index = getIndexByTrackingNumber(trackingNumber);

        if(index == -1)
            return false;

        updateByIndex(index, updatedValue);
        return true;
    }

    /**
     * Create shipment object in database
     *
     * @param trackingNumber of new object
     * @param senderUsername should exist as customer in database
     * @param receiverUsername should exist as customer in database
     * @param operatingBranchName should exist as branch in database
     * @return creation success, false if the parameters requirements does not met
     */
    public boolean createNewShipment(int trackingNumber, String senderUsername, String receiverUsername, String operatingBranchName) {
        if(getByTrackingNumber(trackingNumber) != null) {
            System.out.println("Duplicate trackingNumber for new shipment!");
            return false;
        }

        Customer sender = customerController.getByUsername(senderUsername);
        if(sender == null) {
            System.out.println("Sender username not found!");
            return false;
        }

        Customer receiver = customerController.getByUsername(receiverUsername);
        if(receiver == null) {
            System.out.println("Receiver username not found!");
            return false;
        }

        Branch branch = branchController.getByName(operatingBranchName);
        if(branch == null) {
            System.out.println("Branch not found!");
            return false;
        }

        Shipment shipment = new Shipment(trackingNumber, sender, receiver, branch);

        create(shipment);

        return true;
    }
}
