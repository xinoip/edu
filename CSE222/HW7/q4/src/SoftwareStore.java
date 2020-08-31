import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SoftwareStore {

    /**
     * Search Switch used for changing compareTo method of Software class
     */
    private enum SearchSwitch {
        ByName, ByPrice, ByQuantity
    }

    /**
     * Dummy admin password
     */
    private static final String PASSWORD = "1234";
    /**
     * Current mode of searching
     */
    private SearchSwitch currentSearchSwitch = SearchSwitch.ByName;

    /**
     * Bst with primary key of name
     */
    private MyBstInterface<Software> bstStoreByName;
    /**
     * Bst with primary key of price
     */
    private MyBstInterface<Software> bstStoreByPrice;
    /**
     * Bst with primary key of quantity
     */
    private MyBstInterface<Software> bstStoreByQuantity;

    /**
     * User input
     */
    private Scanner sc;

    /**
     * Get he implementation from outside by basic dependency injection
     * Then create 3 trees with that implementation detail
     * 
     * Got the implementation detail from java reflections
     * 
     * @param bstStore bst implementation of store
     * @param sc user input
     * @throws InstantiationException on wrong implementation
     * @throws IllegalAccessException on wrong implementation
     */
    public SoftwareStore(MyBstInterface<Software> bstStore, Scanner sc) throws InstantiationException, IllegalAccessException {
        this.bstStoreByName = bstStore.getClass().newInstance();
        this.bstStoreByPrice = bstStore.getClass().newInstance();
        this.bstStoreByQuantity = bstStore.getClass().newInstance();
        this.sc = sc;
        seedStore();
    }

    /**
     * Seed store with given data on pdf
     */
    private void seedStore() {
        List<Software> mySoftwares = new ArrayList<>();
        mySoftwares.add(new Software("Adobe Photoshop 6.0", 120, 50));
        mySoftwares.add(new Software("Adobe Photoshop 6.2", 150, 50));
        mySoftwares.add(new Software("Norton 4.5", 100, 100));
        mySoftwares.add(new Software("Norton 5.5", 160, 60));
        mySoftwares.add(new Software("Adobe Flash 3.3", 25, 30));
        mySoftwares.add(new Software("Adobe Flash 4.0", 35, 50));

        for (Software software : mySoftwares) {
            addSoftware(software);
        }
    }

    /**
     * Add manager for 3 bsts, it adds the software to all trees
     * Before adding changes the SearchSwitch, for correct bst behaviour
     * 
     * @param software software to add
     */
    private void addSoftware(Software software) {
        if (software.quantity == 0)
            return;
        currentSearchSwitch = SearchSwitch.ByName;
        bstStoreByName.put(software);
        currentSearchSwitch = SearchSwitch.ByPrice;
        bstStoreByPrice.put(software);
        currentSearchSwitch = SearchSwitch.ByQuantity;
        bstStoreByQuantity.put(software);
    }

    /**
     * Delete manager for 3 bsts, it deletes the software from all trees
     * Before deleting changes the SearchSwitch, for correct bst behaviour
     * 
     * @param software software to delete
     */
    private Software deleteSoftware(Software software) {
        currentSearchSwitch = SearchSwitch.ByName;
        bstStoreByName.remove(software);
        currentSearchSwitch = SearchSwitch.ByPrice;
        bstStoreByPrice.remove(software);
        currentSearchSwitch = SearchSwitch.ByQuantity;
        return bstStoreByQuantity.remove(software);
    }

    /**
     * Update manager for 3 bsts, it updates the software from all trees
     * Before update changes the SearchSwitch, for correct bst behaviour
     * 
     * @param software software to update
     * @param updatedSoftware updated version of software
     */
    private boolean updateSoftware(Software software, Software updatedSoftware) {
        Software found = deleteSoftware(software);
        if (found != null) {
            addSoftware(updatedSoftware);
            return true;
        } else {
            return false;
        }
    }

    /**
     * Show store sorted by name
     */
    private void printStoreByName() {
        for (Software software : bstStoreByName) {
            System.out.println(software);
        }
    }

    /**
     * Show store sorted by price
     */
    private void printStoreByPrice() {
        for (Software software : bstStoreByPrice) {
            System.out.println(software);
        }
    }

    /**
     * Show store sorted by quantity
     */
    private void printStoreByQuantity() {
        for (Software software : bstStoreByQuantity) {
            System.out.println(software);
        }
    }

    /**
     * Custom Software data class for softwares
     */
    public class Software implements Comparable<Software> {
        /**
         * Name of software
         */
        public final String name;
        /**
         * Price of software
         */
        public final int price;
        /**
         * Quantity of software
         */
        public final int quantity;

        /**
         * Create software data class from arguments
         * 
         * @param name
         * @param price
         * @param quantity
         */
        public Software(String name, int price, int quantity) {
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }

        /**
         * Change-able compareTo function
         * This methods behaviour changes according to searchSwitch state
         */
        @Override
        public int compareTo(Software o) {
            switch (currentSearchSwitch) {
                case ByName:
                    return this.name.compareTo(o.name);
                case ByPrice:
                    return this.price - o.price;
                case ByQuantity:
                    return this.quantity - o.quantity;
                default:
                    return 0;
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(name + ", ");
            sb.append("$" + price + ", ");
            sb.append(quantity + " In Stock");
            return sb.toString();
        }
    }

    /**
     * User ui
     */
    private void printUserInterface() {
        System.out.println("====== Software Store ======");
        System.out.println("1- Search by name");
        System.out.println("2- Search by quantity");
        System.out.println("3- Search by price");
        System.out.println("4- Admin Login");
        System.out.println("5- Show store stock by name");
        System.out.println("6- Show store stock by price");
        System.out.println("7- Show store stock by quantity");
        System.out.println("0- Exit");
    }

    /**
     * Admin ui
     */
    private void printAdminInterface() {
        System.out.println("====== Software Store (Admin) ======");
        System.out.println("1- Show store stock");
        System.out.println("2- Update Software");
        System.out.println("3- Delete Software");
        System.out.println("4- Add Software");
        System.out.println("0- Log out");
    }

    /**
     * Main Store loop that handles inputs/outputs
     */
    public void storeLoop() {
        boolean isAdmin = false;
        boolean running = true;

        while (running) {

            if (isAdmin) {
                printAdminInterface();
            } else {
                printUserInterface();
            }

            int input = sc.nextInt();

            switch (input) {
                case 0:
                    if (isAdmin) {
                        isAdmin = false;
                    } else {
                        System.out.println("Good bye!");
                        running = false;
                    }
                    break;
                case 1:
                    if (isAdmin) {
                        printStoreByName();
                    } else {
                        System.out.print("Search by name: ");
                        sc.nextLine();
                        String search = sc.nextLine();
                        currentSearchSwitch = SearchSwitch.ByName;
                        Software software = bstStoreByName.search(new Software(search, 0, 0));
                        if (software != null) {
                            System.out.println("Found software: " + software);
                        } else {
                            System.out.println("Software not found!");
                        }
                    }
                    break;
                case 2:
                    if (isAdmin) {
                        System.out.print("Enter name of software: ");
                        sc.nextLine();
                        String search = sc.nextLine();
                        currentSearchSwitch = SearchSwitch.ByName;
                        Software software = bstStoreByName.search(new Software(search, 0, 0));
                        if (software != null) {
                            System.out.println("Found software: " + software);

                            System.out.print("Enter new name (or leave blank for unchanged): ");
                            String newName = sc.nextLine();
                            if(newName.isEmpty()) {
                                newName = software.name;
                            }

                            System.out.print("Enter new quantity (or -1 for unchanged): ");
                            int newQuantity = sc.nextInt();
                            if(newQuantity == -1) {
                                newQuantity = software.quantity;
                            }

                            System.out.print("Enter new price (or -1 for unchaged): ");
                            int newPrice = sc.nextInt();
                            if(newPrice == -1) {
                                newPrice = software.price;
                            }

                            boolean result = updateSoftware(software, new Software(newName, newPrice, newQuantity));
                            if(result) {
                                System.out.println("Updated software!");
                            } else {
                                System.out.println("Update failed!");
                            }
                        } else {
                            System.out.println("Software not found!");
                        }
                    } else {
                        System.out.println("Search by quantity: ");
                        int quantitySearch = sc.nextInt();
                        currentSearchSwitch = SearchSwitch.ByQuantity;
                        Software software = bstStoreByQuantity.search(new Software("", 0, quantitySearch));
                        if (software != null) {
                            System.out.println("Found software: " + software);
                        } else {
                            System.out.println("Software not found!");
                        }
                    }
                    break;
                case 3:
                    if (isAdmin) {
                        System.out.print("Enter name of software: ");
                        sc.nextLine();
                        String search = sc.nextLine();
                        currentSearchSwitch = SearchSwitch.ByName;
                        Software software = bstStoreByName.search(new Software(search, 0, 0));
                        if (software != null) {
                            System.out.println("Found software: " + software);
                            deleteSoftware(software);
                            System.out.println("Deleted software!");
                        } else {
                            System.out.println("Software not found!");
                        }
                    } else {
                        System.out.println("Search by price: ");
                        int priceSearch = sc.nextInt();
                        currentSearchSwitch = SearchSwitch.ByPrice;
                        Software software = bstStoreByQuantity.search(new Software("", priceSearch, 0));
                        if (software != null) {
                            System.out.println("Found software: " + software);
                        } else {
                            System.out.println("Software not found!");
                        }
                    }
                    break;
                case 4:
                    if (isAdmin) {
                        System.out.print("Enter name: ");
                        sc.nextLine();
                        String newName = sc.nextLine();

                        System.out.print("Enter quantity: ");
                        int newQuantity = sc.nextInt();

                        System.out.print("Enter price: ");
                        int newPrice = sc.nextInt();

                        addSoftware(new Software(newName, newPrice, newQuantity));
                    } else {
                        if (isAdmin) {
                            System.out.println("Invalid input!");
                        } else {
                            System.out.print("Password ps(" + PASSWORD + "): ");
                            sc.nextLine();
                            String pass = sc.nextLine();
                            if (pass.equals(PASSWORD)) {
                                isAdmin = true;
                            } else {
                                System.out.println("Wrong password!");
                            }
                        }
                    }
                    break;
                case 5:
                    if (isAdmin) {
                        System.out.println("Invalid input!");
                    } else {
                        printStoreByName();
                    }
                    break;
                case 6:
                    if (isAdmin) {
                        System.out.println("Invalid input!");
                    } else {
                        printStoreByPrice();
                    }
                    break;
                case 7:
                    if (isAdmin) {
                        System.out.println("Invalid input!");
                    } else {
                        printStoreByQuantity();
                    }
                    break;
                default:
                    System.out.println("Invalid input!");
                    break;
            }

        }
    }

}