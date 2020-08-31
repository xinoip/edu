package com.pionix;

/**
 * Shipment is a real-life cargo shipment
 */
public class Shipment {
    private final int trackingNumber;
    private ShipmentStatusEnum status;
    private final Customer sender;
    private final Customer receiver;
    private final Branch branch;

    public enum ShipmentStatusEnum {
        LEFT, ENTERED, DELIVERED, UNINITIALIZED
    }

    public Shipment(int trackingNumber, Customer sender, Customer receiver, Branch branch) {
        this.trackingNumber = trackingNumber;
        this.sender = sender;
        this.receiver = receiver;
        this.branch = branch;

        status = ShipmentStatusEnum.ENTERED;
    }

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
