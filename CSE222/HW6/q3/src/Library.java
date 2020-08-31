import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * Library class is a library automation class with user interfaces
 */
public class Library {
    /**
     * Internal storage of library
     */
    private Map<String, Map<String, Set<BookLocation>>> store;
    /**
     * Scanner to get input from outside world
     */
    private final Scanner sc;

    /**
     * Default constructor
     * 
     * @param sc scanner for input handling
     */
    Library(Scanner sc) {
        store = new HashMap<>();
        this.sc = sc;
        seedStore();
    }

    /**
     * Seeds the library with some data to play with
     */
    private void seedStore() {
        HashMap<String, Set<BookLocation>> aytmatov = new HashMap<>();
        HashMap<String, Set<BookLocation>> inalcik = new HashMap<>();
        aytmatov.put("The_White_Ship", new HashSet<>());
        aytmatov.get("The_White_Ship").add(new BookLocation(1, 1, 1));
        aytmatov.get("The_White_Ship").add(new BookLocation(1, 2, 2));

        aytmatov.put("Plakha", new HashSet<BookLocation>());
        aytmatov.get("Plakha").add(new BookLocation(1, 1, 1));

        store.put("Aytmatov", aytmatov);

        inalcik.put("The_Ottoman_Empire", new HashSet<>());
        inalcik.get("The_Ottoman_Empire").add(new BookLocation(4, 3, 12));
        inalcik.get("The_Ottoman_Empire").add(new BookLocation(6, 2, 10));
        inalcik.get("The_Ottoman_Empire").add(new BookLocation(6, 3, 11));
        inalcik.put("The_Classical_Age", new HashSet<>());
        inalcik.get("The_Classical_Age").add(new BookLocation(1, 9, 121));

        store.put("Inalcik", inalcik);
    }

    /**
     * Searches by author and lists authors books, if found
     * Then prompts user for selecting a book
     * With the input, shows the selected books locations
     * 
     * @param author author name to search with
     */
    public void searchByAuthor(String author) {
        System.out.println("Searching author: " + author);
        Map<String, Set<BookLocation>> books = store.get(author);
        int index = 1;
        System.out.println("Listing books of Author " + author);
        for (Map.Entry<String, Set<BookLocation>> entry : books.entrySet()) {
            System.out.print(index + "- ");
            System.out.println(entry.getKey());
            index++;
        }
        System.out.print("Select book: ");
        int selected = sc.nextInt();
        index = 1;
        boolean success = false;
        for (Map.Entry<String, Set<BookLocation>> entry : books.entrySet()) {
            if (index == selected) {
                success = true;
                System.out.println("Locations found for book " + entry.getKey());
                System.out.println(entry.getValue());
            }
            index++;
        }
        if (!success) {
            System.out.println("Selection is not valid.");
        }
    }

    /**
     * Searchs by book name
     * If the book is found, then displays every information about that book
     * 
     * @param book book name to search with
     */
    public void searchByBook(String book) {
        System.out.println("Searching book: " + book);
        boolean success = false;
        for (Map.Entry<String, Map<String, Set<BookLocation>>> authorEntry : store.entrySet()) {
            for (Map.Entry<String, Set<BookLocation>> bookEntry : authorEntry.getValue().entrySet()) {
                if (bookEntry.getKey().equals(book)) {
                    System.out.println("Found book: " + book);
                    System.out.println("Author of book: " + authorEntry.getKey());
                    System.out.println("Locations of book: " + bookEntry.getValue());
                    success = true;
                }
            }
        }
        if (!success) {
            System.out.println("Not found: " + book);
        }
    }

    /**
     * Prompts user with inputs, that results to adding a book to system
     * 
     * If the author is a new author, it creates the author then adds the book
     * If the author is an existing author, it just adds the book to existing author
     * If the book is an existing book, it just adds a new location for that book
     */
    public void addBook() {
        System.out.print("Enter name of book: ");
        String bookName = sc.next();
        System.out.print("Enter corridor of book: ");
        int corridor = sc.nextInt();
        System.out.print("Enter shelf of book: ");
        int shelf = sc.nextInt();
        System.out.print("Enter id of book: ");
        int id = sc.nextInt();
        System.out.print("Enter author of book: ");
        String author = sc.next();

        boolean existingAuthor = false;
        boolean existingBook = false;
        for (Map.Entry<String, Map<String, Set<BookLocation>>> authorEntry : store.entrySet()) {
            for (Map.Entry<String, Set<BookLocation>> bookEntry : authorEntry.getValue().entrySet()) {
                if (authorEntry.getKey().equals(author)) {
                    existingAuthor = true;
                }
                if (bookEntry.getKey().equals(bookName)) {
                    existingBook = true;
                }
            }
        }

        if (!existingAuthor) {
            System.out.println("Author does not exist!");
            System.out.println("Created author with given book.");
            HashMap<String, Set<BookLocation>> authorMap = new HashMap<>();
            authorMap.put(bookName, new HashSet<>());
            authorMap.get(bookName).add(new BookLocation(corridor, shelf, id));
            store.put(author, authorMap);
        } else {
            System.out.println("Author with name" + author + " already exists.");
            System.out.println("Adding book to existing author.");
            if (!existingBook) {
                store.get(author).put(bookName, new HashSet<>());
                store.get(author).get(bookName).add(new BookLocation(corridor, shelf, id));
            } else {
                System.out.println("Book with name " + bookName + "already exists.");
                System.out.println("Adding new location for this book.");
                store.get(author).get(bookName).add(new BookLocation(corridor, shelf, id));
            }
        }
        System.out.println();
        System.out.println();
    }

    /**
     * Prompts user with inputs, that results to removing a book from system
     * 
     * If the book is found, it removes the given location of that book.
     * After removal of the location, if there are no more locations left, it removes the book.
     */
    public void deleteBook() {
        System.out.print("Enter name of book: ");
        String bookName = sc.next();
        System.out.print("Enter author of book: ");
        String author = sc.next();

        boolean found = false;
        for (Map.Entry<String, Map<String, Set<BookLocation>>> authorEntry : store.entrySet()) {
            for (Map.Entry<String, Set<BookLocation>> bookEntry : authorEntry.getValue().entrySet()) {
                if (authorEntry.getKey().equals(author) && bookEntry.getKey().equals(bookName)) {
                    found = true;
                }
            }
        }

        if (!found) {
            System.out.println("Book with given author name not found!");
        } else {
            store.get(author).remove(bookName);
            System.out.println("Removed book " + bookName + " from author " + author);
        }
    }

    /**
     * Prompts user with inputs, that results to updating a book in system
     * 
     * If the book is found, it prompts user with new fields.
     * It can update, name of the book and locations of the book.
     */
    public void updateBook() {
        System.out.print("Enter name of book: ");
        String bookName = sc.next();
        System.out.print("Enter author of book: ");
        String author = sc.next();

        boolean found = false;
        for (Map.Entry<String, Map<String, Set<BookLocation>>> authorEntry : store.entrySet()) {
            for (Map.Entry<String, Set<BookLocation>> bookEntry : authorEntry.getValue().entrySet()) {
                if (authorEntry.getKey().equals(author) && bookEntry.getKey().equals(bookName)) {
                    found = true;
                }
            }
        }

        if (!found) {
            System.out.println("Book with given author name not found!");
        } else {
            store.get(author).remove(bookName);

            System.out.print("Enter new name of book: ");
            String ebookName = sc.next();
            System.out.print("Enter new corridor of book: ");
            int ecorridor = sc.nextInt();
            System.out.print("Enter new shelf of book: ");
            int eshelf = sc.nextInt();
            System.out.print("Enter new id of book: ");
            int eid = sc.nextInt();

            store.get(author).put(ebookName, new HashSet<>());
            store.get(author).get(ebookName).add(new BookLocation(ecorridor, eshelf, eid));
        }
    }

    /**
     * Prints storage of the library with every information
     */
    public void printLibrary() {
        for (Map.Entry<String, Map<String, Set<BookLocation>>> authorEntry : store.entrySet()) {
            System.out.println("Author " + authorEntry.getKey());
            for (Map.Entry<String, Set<BookLocation>> bookEntry : authorEntry.getValue().entrySet()) {
                System.out.println("\tBook " + bookEntry.getKey());
                System.out.println("\t\tLocations " + bookEntry.getValue());
            }
        }
    }

    /**
     * For ui printing, initial greet
     */
    public void greet() {
        System.out.println("==============");
        System.out.println("Library System");
        System.out.println("==============");
        System.out.println();
    }

    /**
     * For ui printing, guest menu
     */
    public void guestMenu() {
        System.out.println("=Guest Menu=");
        System.out.println("1- Print Library");
        System.out.println("2- Search by author name");
        System.out.println("3- Search by book name");
        System.out.println("4- Login as Admin");
        System.out.println("0- Exit");
    }

    /**
     * For ui printing, admin menu
     */
    public void adminMenu() {
        System.out.println("=Admin Menu=");
        System.out.println("1- Print Library");
        System.out.println("2- Add book");
        System.out.println("3- Remove book");
        System.out.println("4- Update book");
        System.out.println("0- Log out");
    }

    /**
     * Handling inputs of an admin
     * 
     * @param input input of admin
     * @return callback for logout
     */
    public int adminInput(int input) {
        switch (input) {
            case 0:
                return -1;
            case 1:
                printLibrary();
                break;
            case 2:
                addBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                updateBook();
                break;

            default:
                System.out.println("Invalid input!");
                break;
        }
        return 1;
    }

    /**
     * Handling inputs of a guest
     * 
     * @param input input of guest
     * @return callback for exit or login as admin
     */
    public int guestInput(int input) {
        switch (input) {
            case 0:
                return -1;
            case 1:
                printLibrary();
                break;
            case 2:
                System.out.println("Enter author: ");
                String author = sc.next();
                searchByAuthor(author);
                break;
            case 3:
                System.out.println("Enter book: ");
                String book = sc.next();
                searchByBook(book);
                break;
            case 4:
                return 0;

            default:
                System.out.println("Invalid input!");
                break;
        }
        return 1;
    }

}