import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        MyBstInterface<SoftwareStore.Software> myBst = new MyBst<>();
        SoftwareStore store;
        Scanner sc = new Scanner(System.in);
        try {
            store = new SoftwareStore(myBst, sc);
            store.storeLoop();
        } catch (InstantiationException | IllegalAccessException e) {
            e.printStackTrace();
        }

        sc.close();
    }

}