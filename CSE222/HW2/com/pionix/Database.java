package com.pionix;

import com.pionix.controllers.*;

/**
 * Database class is the holder of all controllers
 *
 * Controllers are singleton, the class attempts to mimic a real life database.
 *
 * Also this class seeds the initial data.
 */
public class Database {
    /**
     * AdministratorController holds the Table for Administrator objects.
     * Has the actions for it
     */
    public static AdministratorController administratorController = new AdministratorController();
    /**
     * BranchController holds the Table for Branch objects.
     * Has the actions for it
     */
    public static BranchController branchController = new BranchController();
    /**
     * BranchEmployeeController holds the Table for BranchEmployee objects.
     * Has the actions for it
     */
    public static BranchEmployeeController branchEmployeeController = new BranchEmployeeController(branchController);
    /**
     * CustomerController holds the Table for Customer objects.
     * Has the actions for it
     */
    public static CustomerController customerController = new CustomerController();
    /**
     * ShipmentController holds the Table for Shipment objects.
     * Has the actions for it
     */
    public static ShipmentController shipmentController = new ShipmentController(customerController, branchController);
    /**
     * TransportationController holds the Table for Transportation objects.
     * Has the actions for it
     */
    public static TransportationPersonnelController transportationPersonnelController = new TransportationPersonnelController();

    /**
     * Seeds the database with some initial data for every model
     */
    public static void seedDatabase() {
        administratorController.create("Pionix");
        administratorController.create("xinoiP");

        customerController.create("Kerem");
        customerController.create("Eren");
        customerController.create("Asya");
        customerController.create("Fatma");
        customerController.create("Hakan");

        branchController.createNewBranch("Ankara");
        branchController.createNewBranch("Istanbul");
        branchController.createNewBranch("Izmir");
        branchController.createNewBranch("Adana");

        branchEmployeeController.create("Haydar", "Ankara");
        branchEmployeeController.create("Mehmet", "Ankara");
        branchEmployeeController.create("Abdul", "Istanbul");
        branchEmployeeController.create("Kaan", "Izmir");
        branchEmployeeController.create("Emir", "Adana");

        transportationPersonnelController.create("Buse");
        transportationPersonnelController.create("Ali");
        transportationPersonnelController.create("Yagiz");

        shipmentController.createNewShipment(100001, "Hakan", "Fatma", "Ankara");
        shipmentController.createNewShipment(100002, "Asya", "Kerem", "Izmir");
    }

    /**
     * Clear the database
     */
    public static void resetDatabase() {
        administratorController.clear();
        branchController.clear();
        branchEmployeeController.clear();
        customerController.clear();
        transportationPersonnelController.clear();
        shipmentController.clear();
    }
}




























