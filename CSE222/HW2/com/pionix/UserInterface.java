package com.pionix;

import java.util.Scanner;
import com.pionix.models.*;

/**
 * UserInterface class is just for the demo of the system
 *
 * The system can be used as back-end for anything that has a front-end ready
 */
public class UserInterface {

    /**
     * Current user
     */
    private static User user;
    private static Scanner sc = new Scanner(System.in);

    /**
     * Login menu printing and input handling
     */
    public static void loginMenu() {
        boolean running = true;
        while (user == null && running) {
            System.out.println("====== LOG-IN ======");
            System.out.println("Example users: Admin(Pionix), BranchEmployee(Haydar), TPEmployee(Ali), Customer(Asya), Customer(Kerem)");
            System.out.println("Check the seeder of database at Database class!");
            System.out.println("1- Admin");
            System.out.println("2- Branch Employee");
            System.out.println("3- Transportation Employee");
            System.out.println("4- Customer");
            System.out.println("5- Exit the system");
            int selection = sc.nextInt();

            String input;
            switch (selection) {
                case 1:
                    System.out.print("Username: ");
                    input = sc.next();
                    user = Database.administratorController.getByUsername(input);

                    if(user == null)
                        System.out.println("Username not found!");
                    break;
                case 2:
                    System.out.print("Username: ");
                    input = sc.next();
                    user = Database.branchEmployeeController.getByUsername(input);

                    if(user == null)
                        System.out.println("Username not found!");
                    break;
                case 3:
                    System.out.print("Username: ");
                    input = sc.next();
                    user = Database.transportationPersonnelController.getByUsername(input);

                    if(user == null)
                        System.out.println("Username not found!");
                    break;
                case 4:
                    System.out.print("Username: ");
                    input = sc.next();
                    user = Database.customerController.getByUsername(input);

                    if(user == null)
                        System.out.println("Username not found!");
                    break;
                case 5:
                    running = false;
                    System.out.println("Bye bye..");
                    break;
                default:
                    System.out.println("Selection not on the list!");
                    break;
            }
        }

        if(user instanceof Administrator) {
            adminMenu();
        } else if(user instanceof BranchEmployee) {
            branchEmployeeMenu();
        } else if(user instanceof TransportationPersonnel) {
            transportationPersonnelMenu();
        } else if(user instanceof Customer) {
            customerMenu();
        } else if(user == null){
            // do nothing
        } else {
            System.out.println("Something went wrong in login menu!");
        }
    }

    /**
     * Admin menu printing and input handling
     */
    public static void adminMenu() {
        Administrator admin = (Administrator) user;
        boolean logout = false;
        while(!logout) {
            System.out.println("====== ADMIN ======");
            System.out.println("1- Add Branch");
            System.out.println("2- Remove Branch");
            System.out.println("3- List Branches");
            System.out.println("4- Add Branch Employee");
            System.out.println("5- Remove Branch Employee");
            System.out.println("6- List Branch Employees");
            System.out.println("7- Add Transportation Employee");
            System.out.println("8- Remove Transportation Personnel");
            System.out.println("9- List Transportation Personnel");
            System.out.println("10- List Shipments");
            System.out.println("11- List Customers");
            System.out.println("0- Logout");
            int selection = sc.nextInt();

            String input, input2;
            boolean result = true;
            switch (selection) {
                case 1:
                    System.out.print("Enter name of the new branch: ");
                    input = sc.next();
                    result = admin.access.branchController.createNewBranch(input);
                    break;
                case 2:
                    System.out.print("Enter name of the branch to delete: ");
                    input = sc.next();
                    result = admin.access.branchController.deleteByName(input);
                    break;
                case 3:
                    admin.access.branchController.print();
                    break;
                case 4:
                    System.out.print("Enter username of the new employee: ");
                    input = sc.next();
                    System.out.print("Enter name of the branch to station employee: ");
                    input2 = sc.next();
                    result = admin.access.branchEmployeeController.create(input, input2);
                    break;
                case 5:
                    System.out.print("Enter username of the employee to delete: ");
                    input = sc.next();
                    result = admin.access.branchEmployeeController.deleteByUsername(input);
                    break;
                case 6:
                    admin.access.branchEmployeeController.print();
                    break;
                case 7:
                    System.out.print("Enter username of the new personnel: ");
                    input = sc.next();
                    result = admin.access.transportationPersonnelController.create(input);
                    break;
                case 8:
                    System.out.print("Enter username of the new personnel to delete: ");
                    input = sc.next();
                    result = admin.access.transportationPersonnelController.deleteByUsername(input);
                    break;
                case 9:
                    admin.access.transportationPersonnelController.print();
                    break;
                case 10:
                    admin.access.shipmentController.print();
                    break;
                case 11:
                    admin.access.customerController.print();
                    break;
                case 0:
                    logout = true;
                    System.out.println("Goodbye " + user.getUsername() + ".");
                    user = null;
                    break;
            }

            if(result)
                System.out.println("Operation was successful!\n");
            else
                System.out.println("Operation was NOT successful!\n");
        }

        loginMenu();
    }

    /**
     * BranchEmployee menu printing and input handling
     */
    public static void branchEmployeeMenu() {
        BranchEmployee employee = (BranchEmployee) user;
        boolean logout = false;
        while(!logout) {
            System.out.println("====== Branch Employee [at] " + employee.getBranch().getName() + "======");
            System.out.println("1- Add Shipment");
            System.out.println("2- Register Shipment Exit from branch");
            System.out.println("3- Remove Shipment");
            System.out.println("4- List Shipments");
            System.out.println("5- Add Customer");
            System.out.println("6- Remove Customer");
            System.out.println("7- List Customers");
            System.out.println("0- Logout");
            int selection = sc.nextInt();

            String input, input2, input3;
            int inputInt;
            boolean result = true;
            switch (selection) {
                case 1:
                    System.out.print("Enter tracking number of the new shipment: ");
                    input = sc.next();
                    System.out.print("Enter username of sender: ");
                    input2 = sc.next();
                    System.out.print("Enter username of receiver: ");
                    input3 = sc.next();
                    result = employee.access.shipmentController.createNewShipment(Integer.parseInt(input), input2, input3, employee.getBranch().getName());
                    break;
                case 2:
                    System.out.print("Enter tracking number of the shipment to change: ");
                    inputInt = sc.nextInt();

                    Shipment shipment = employee.access.shipmentController.getByTrackingNumber(inputInt);
                    if(shipment != null)
                        shipment.setStatus(Shipment.ShipmentStatusEnum.LEFT);
                    else
                        System.out.println("Shipment not found!");

                    result = employee.access.shipmentController.updateByTrackingNumber(inputInt, shipment);
                    break;
                case 3:
                    System.out.print("Enter tracking number of the shipment to remove: ");
                    inputInt = sc.nextInt();
                    result = employee.access.shipmentController.deleteByTrackingNumber(inputInt);
                    break;
                case 4:
                    employee.access.shipmentController.print();
                    break;
                case 5:
                    System.out.print("Enter username of the new customer: ");
                    input = sc.next();
                    result = employee.access.customerController.create(input);
                    break;
                case 6:
                    System.out.print("Enter username of the customer to delete: ");
                    input = sc.next();
                    result = employee.access.customerController.deleteByUsername(input);
                    break;
                case 7:
                    employee.access.customerController.print();
                    break;
                case 0:
                    logout = true;
                    System.out.println("Goodbye " + user.getUsername() + ".");
                    user = null;
                    break;
            }

            if(result)
                System.out.println("Operation was successful!\n");
            else
                System.out.println("Operation was NOT successful!\n");
        }

        loginMenu();
    }

    /**
     * Customer menu printing and input handling
     */
    public static void customerMenu() {
        Customer customer = (Customer) user;
        boolean logout = false;
        while(!logout) {
            System.out.println("====== Customer ======");
            System.out.println("1- Check Shipment");
            System.out.println("0- Logout");
            int selection = sc.nextInt();

            int inputInt;
            boolean result = true;
            switch (selection) {
                case 1:
                    System.out.print("Enter tracking number of the shipment: ");
                    inputInt = sc.nextInt();

                    Shipment shipment;
                    shipment = customer.access.shipmentController.getByTrackingNumber(inputInt);
                    if(shipment != null)
                        System.out.println(shipment);
                    else
                        System.out.println("Shipment not found!");
                    break;
                case 0:
                    logout = true;
                    System.out.println("Goodbye " + user.getUsername() + ".");
                    user = null;
                    break;
            }

            if(result)
                System.out.println("Operation was successful!\n");
            else
                System.out.println("Operation was NOT successful!\n");
        }

        loginMenu();
    }

    /**
     * TransportationPersonnel menu printing and input handling
     */
    public static void transportationPersonnelMenu() {
        TransportationPersonnel personnel = (TransportationPersonnel) user;
        boolean logout = false;
        while(!logout) {
            System.out.println("====== Transportation Personnel ======");
            System.out.println("1- Deliver Shipment");
            System.out.println("0- Logout");
            int selection = sc.nextInt();

            int inputInt;
            boolean result = true;
            switch (selection) {
                case 1:
                    System.out.print("Enter tracking number of the shipment: ");
                    inputInt = sc.nextInt();

                    Shipment shipment = personnel.access.shipmentController.getByTrackingNumber(inputInt);
                    shipment.setStatus(Shipment.ShipmentStatusEnum.DELIVERED);
                    result = personnel.access.shipmentController.updateByTrackingNumber(inputInt, shipment);
                    if(shipment != null)
                        System.out.println(shipment);
                    else
                        System.out.println("Shipment not found!");
                    break;
                case 0:
                    logout = true;
                    System.out.println("Goodbye " + user.getUsername() + ".");
                    user = null;
                    break;
            }

            if(result)
                System.out.println("Operation was successful!\n");
            else
                System.out.println("Operation was NOT successful!\n");
        }

        loginMenu();
    }

}
