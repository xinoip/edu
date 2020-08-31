/**
 * FileSystemTree adding tests
 */
public class AddTester {
    private static void print(String str) {
        System.out.print(str);
    }

    public static void t_printTree() {
        print("Test: Adding some directories and files to demonstrate printing of a tree.\n");
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
        myFileSystem.printFileSystem();
    }

    public static void t_addDirUnderDir() {
        print("Test: Adding a directory under another directory\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("After adding directory under first_directory:\n");
        try {
            myFileSystem.addDir("root/first_directory/second_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addFileUnderDir() {
        print("Test: Adding a file under another directory\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("After adding file Foo.txt under first_directory:\n");
        try {
            myFileSystem.addFile("root/first_directory/Foo.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addDirUnderFile() {
        print("Test: Trying to add a directory under a file\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addFile("root/first_directory/Foo.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to add second_directory under Foo.txt:\n");
        try {
            myFileSystem.addDir("root/first_directory/Foo.txt/second_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addFileUnderFile() {
        print("Test: Trying to add a file under another file\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addFile("root/first_directory/Foo.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to add file homework.txt under Foo.txt:\n");
        try {
            myFileSystem.addFile("root/first_directory/Foo.txt/homework.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addExistingDir() {
        print("Test: Trying to add a directory that already exists\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/hw.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to add second_directory again:\n");
        try {
            myFileSystem.addDir("root/second_directory");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addExistingFile() {
        print("Test: Trying to add a file that already exists\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/hw.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to add hw.txt under first_directory, again:\n");
        try {
            myFileSystem.addFile("root/first_directory/hw.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }

    public static void t_addUnderNonExistingDir() {
        print("Test: Trying to add a file under non existing directory\n");
        FileSystemTree myFileSystem = new FileSystemTree("root");
        try {
            myFileSystem.addDir("root/first_directory");
            myFileSystem.addDir("root/second_directory");
            myFileSystem.addFile("root/first_directory/hw.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        print("Initial tree:\n");
        myFileSystem.printFileSystem();
        print("Trying to add foo.txt under root/second/third/fourth:\n");
        try {
            myFileSystem.addFile("root/second/third/fourth/foo.txt");
        } catch (Exception e) {
            print(e.toString() + "\n");
        }
        myFileSystem.printFileSystem();
    }
}