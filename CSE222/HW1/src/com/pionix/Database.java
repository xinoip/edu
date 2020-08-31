package com.pionix;

/**
 * Database class is the holder of all controllers
 *
 * Controllers are singleton, the class attempts to mimic a real life database.
 *
 * Also this class seeds the initial data.
 */
public class Database {
    public static AdministratorController administratorController = new AdministratorController();
    public static BranchController branchController = new BranchController();
    public static BranchEmployeeController branchEmployeeController = new BranchEmployeeController(branchController);
    public static CustomerController customerController = new CustomerController();
    public static ShipmentController shipmentController = new ShipmentController(customerController, branchController);
    public static TransportationPersonnelController transportationPersonnelController = new TransportationPersonnelController();

    /**
     * Seeds the database with some initial data for every model
     */
    public static void seedDatabase() {
        administratorController.createNewAdministrator("Pionix");
        administratorController.createNewAdministrator("xinoiP");

        customerController.createNewCustomer("Kerem");
        customerController.createNewCustomer("Eren");
        customerController.createNewCustomer("Asya");
        customerController.createNewCustomer("Fatma");
        customerController.createNewCustomer("Hakan");

        branchController.createNewBranch("Ankara");
        branchController.createNewBranch("Istanbul");
        branchController.createNewBranch("Izmir");
        branchController.createNewBranch("Adana");

        branchEmployeeController.createNewBranchEmployee("Haydar", "Ankara");
        branchEmployeeController.createNewBranchEmployee("Mehmet", "Ankara");
        branchEmployeeController.createNewBranchEmployee("Abdul", "Istanbul");
        branchEmployeeController.createNewBranchEmployee("Kaan", "Izmir");
        branchEmployeeController.createNewBranchEmployee("Emir", "Adana");

        transportationPersonnelController.createNewTransportationPersonnel("Buse");
        transportationPersonnelController.createNewTransportationPersonnel("Ali");
        transportationPersonnelController.createNewTransportationPersonnel("Yagiz");

        shipmentController.createNewShipment(100001, "Hakan", "Fatma", "Ankara");
        shipmentController.createNewShipment(100002, "Asya", "Kerem", "Izmir");
    }

    /**
     * Test cases for access of user roles to database controllers
     */
    public static void accessTestCases() {
        PersonRole user;

        // Get the BranchEmployee named Mehmet from database
        user = Database.branchEmployeeController.getByUsername("Mehmet");

        // Down-case user object to role
        BranchEmployee employee = (BranchEmployee) user;

        // Access the employees abilities
        // Just examples
        // Wont create anything because there is no such customer named Foo and Goo
        // No such branch named FooBranch
        employee.access.customerController.getByUsername("Foo");

        // No such tracking number
        employee.access.shipmentController.getByTrackingNumber(123);

        // Get the TPEmployee named Ali from database
        user = Database.transportationPersonnelController.getByUsername("Ali");
        
        // Down-case user object to role
        TransportationPersonnel tPersonnel = (TransportationPersonnel) user;

        // Access the tPersonnels abilities
        tPersonnel.access.shipmentController.getByIndex(0);

        user = Database.administratorController.getByUsername("AdminName");
        Administrator admin = (Administrator) user;
    }
}




























