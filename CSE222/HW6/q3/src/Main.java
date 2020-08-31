import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library lib = new Library(sc);

        boolean running = true;
        boolean isGreet = true;
        boolean isAdmin = false;
        int input = 0;
        int res = 0;
        while (running) {
            if (isGreet) {
                lib.greet();
                isGreet = false;
            }

            if (isAdmin) {
                lib.adminMenu();
            } else {
                lib.guestMenu();
            }

            System.out.print("> ");
            input = sc.nextInt();
            if (isAdmin) {
                res = lib.adminInput(input);
                if(res == -1) {
                    System.out.println("Logged out");
                    isAdmin = false;
                }
            } else {
                res = lib.guestInput(input);
                if(res == -1) {
                    running = false;
                } else if(res == 0) {
                    System.out.print("Enter admin password (ps. 1234): ");
                    String pass = sc.next();
                    if(pass.equals("1234")) {
                        System.out.println("Logged in as admin");
                        isAdmin = true;
                    } else {
                        System.out.println("Wrong password");
                    }
                }
            }
            System.out.println("\n");
        }

        sc.close();
    }

}