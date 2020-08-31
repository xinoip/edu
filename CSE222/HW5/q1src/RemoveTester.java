/**
 * FileSystemTree removing tests
 */
public class RemoveTester {
    private static void print(String str) {
        System.out.print(str);
    }

    public static void t_removeDirTree() {
        print("Test: Remove a dir that contains a lot of things\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/new_file.txt");
            myFileSystem.addDir("root/second_directory/new_directory");
            myFileSystem.addFile("root/second_directory/new_directory/new_file.doc");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("After request removing second_directory, it will print the contents of target and prompt user with y or n:\n");
        try {
            myFileSystem.remove("root/second_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_removeNonExisting() {
        print("Test: Remove a non existing dir\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/new_file.txt");
            myFileSystem.addDir("root/second_directory/new_directory");
            myFileSystem.addFile("root/second_directory/new_directory/new_file.doc");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to remove root/secdir:\n");
        try {
            myFileSystem.remove("root/secdir");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_removeFile() {
        print("Test: Remove a file\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/new_file.txt");
            myFileSystem.addDir("root/second_directory/new_directory");
            myFileSystem.addFile("root/second_directory/new_directory/new_file.doc");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to remove root/first_directory/new_file.txt:\n");
        try {
            myFileSystem.remove("root/first_directory/new_file.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_removeNonExistingFile() {
        print("Test: Remove a non existing file\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/new_file.txt");
            myFileSystem.addDir("root/second_directory/new_directory");
            myFileSystem.addFile("root/second_directory/new_directory/new_file.doc");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to remove root/foo.txt:\n");
        try {
            myFileSystem.remove("root/foo.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

}