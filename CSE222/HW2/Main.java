import com.pionix.*;
import com.pionix.models.*;

/**
 * AutoCargo program implements an application that
 * simulates a cargo system.
 *
 * Application's memory is run-time only.
 *
 * Application is trying to mimic a real world database.
 *
 * @author Bugra Eren Yilmaz
 * @version 1.0
 * @since 2020-02-24
 */
public class Main {

    public static void main(String[] args) {
        Database.resetDatabase();
        Database.seedDatabase();
        accessTests();
        creationTests();
        nameDuplicationTests();

        System.out.println("\n\n\n TESTS DONE");
        System.out.println("Please ignore outputs of tests.");
        System.out.println("Unless there is a output like '...test failed!'");
        System.out.println("\n\n");

        UserInterface.loginMenu();
    }

    /**
     * Test cases for access of user roles to database controllers
     */
    public static void accessTests() {
        User user;

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

    public static void creationTests() {
        Administrator admin = Database.administratorController.getByUsername("Pionix");
        BranchEmployee employee = Database.branchEmployeeController.getByUsername("Mehmet");
        TransportationPersonnel personnel = Database.transportationPersonnelController.getByUsername("Ali");
        Customer customer = Database.customerController.getByUsername("Hakan");

        boolean success = false;

        // Should fail because
        // No customer found named Foo and Goo
        // Operating branch is found though
        success = employee.access.shipmentController.createNewShipment(100, "Foo", "Goo", "Ankara");
        if(success) System.out.println("creationTest 1 Failed!");

        // Create foo and goo customers, employee can do that
        success = employee.access.customerController.create("Foo");
        success = employee.access.customerController.create("Goo");

        // Now it should succeed
        success = employee.access.shipmentController.createNewShipment(100, "Foo", "Goo", "Ankara");
        if(!success) System.out.println("creationTest 2 Failed!");

        // Customer can see status of cargo
        success = null != customer.access.shipmentController.getByTrackingNumber(100);
        if(!success) System.out.println("creationTest 3 Failed!");

        // Transportation personnel can deliver cargo
        Shipment shipment = personnel.access.shipmentController.getByTrackingNumber(100);
        shipment.setStatus(Shipment.ShipmentStatusEnum.DELIVERED);
        success = personnel.access.shipmentController.updateByTrackingNumber(100, shipment);
        if(!success) System.out.println("creationTest 4 Failed!");

        // Admin can create new employee
        // This should fail since no branch named foo is found
        success = admin.access.branchEmployeeController.create("New Employee", "Foo");
        if(success) System.out.println("creationTest 5 Failed!");

        // Now create foo branch
        // Notice that it can have the name 'Foo'
        // Even tho we have a customer named 'Foo'
        // This can be achieved because every model
        // is stored in separate data
        success = admin.access.branchController.createNewBranch("Foo");
        if(!success) System.out.println("creationTest 6 Failed!");

        // Now create that employee
        success = admin.access.branchEmployeeController.create("New Employee", "Foo");
        if(!success) System.out.println("creationTest 7 Failed!");
    }

    public static void nameDuplicationTests() {
        Administrator admin = Database.administratorController.getByUsername("Pionix");

        boolean success = false;

        // create CUSTOMER1
        success = admin.access.customerController.create("CUSTOMER1");
        if(!success) System.out.println("nameDuplicationTest failed!");

        // try to create it again
        // it should fail
        success = admin.access.customerController.create("CUSTOMER1");
        if(success) System.out.println("nameDuplicationTest failed!");

        // try to create a transport personnel named CUSTOMER1
        // it should pass
        // this is achieved by storing every model in separate data sets
        // even though a Customer and a TransportPersonnel are both derived
        // from User class, their storage are not at the same place!
        success = admin.access.transportationPersonnelController.create("CUSTOMER1");
        if(!success) System.out.println("nameDuplicationTest failed!");
    }
}
