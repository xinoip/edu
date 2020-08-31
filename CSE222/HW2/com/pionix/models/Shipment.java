package com.pionix.models;

/**
 * Shipment is a real-life cargo shipment
 */
public class Shipment {
    /**
     * Unique Id number for shipment
     */
    private final int trackingNumber;
    /**
     * Status of shipment, left, entered, delivered
     */
    private ShipmentStatusEnum status;
    /**
     * Sender customer
     */
    private final Customer sender;
    /**
     * Receiver customer
     */
    private final Customer receiver;
    /**
     * Last operated on branch
     */
    private final Branch branch;

    /**
     * Available statuses for Shipments
     *
     * left the branch
     * entered the branch
     * delivered
     */
    public enum ShipmentStatusEnum {
        LEFT, ENTERED, DELIVERED, UNINITIALIZED
    }

    /**
     * New shipment
     *
     * @param trackingNumber unique id
     * @param sender customer sender
     * @param receiver customer receiver
     * @param branch acting branch
     */
    public Shipment(int trackingNumber, Customer sender, Customer receiver, Branch branch) {
        this.trackingNumber = trackingNumber;
        this.sender = sender;
        this.receiver = receiver;
        this.branch = branch;

        status = ShipmentStatusEnum.ENTERED;
    }

    /**
     * Get the unique id of shipment
     *
     * @return unique id
     */
    public int getTrackingNumber() {
        return trackingNumber;
    }

    /**
     * Status change for delivery and movements
     * @param status new status
     */
    public void setStatus(ShipmentStatusEnum status) {
        this.status = status;
    }

    @Override
    public String toString() {
        String rtr = trackingNumber + ": [" + sender.getUsername() + "] --> [" + receiver.getUsername() + "]\n\t";
        switch (status) {
            case LEFT:
                rtr += "shipment left the";
                break;
            case ENTERED:
                rtr += "shipment entered the";
                break;
            case DELIVERED:
                rtr += "shipment delivered to the customer from ";
                break;
            case UNINITIALIZED:
                rtr += "shipment had a problem from";
                break;
        }

        rtr += " " + branch.getName() + " branch.";
        return rtr;
    }
}
