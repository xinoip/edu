import java.util.List;

/**
 * Class for starting all of the tests
 */
public class Tester {

    /**
     * Printing snippet
     *
     * @param str str to print
     */
    private static void print(String str) {
        System.out.print(str);
    }

    /**
     * Start every test
     */
    public static void startTests() {
        AddTester.t_printTree();
        print("\n");
        AddTester.t_addDirUnderDir();
        print("\n");
        AddTester.t_addFileUnderDir();
        print("\n");
        AddTester.t_addDirUnderFile();
        print("\n");
        AddTester.t_addFileUnderFile();
        print("\n");
        AddTester.t_addExistingDir();
        print("\n");
        AddTester.t_addExistingFile();
        print("\n");
        AddTester.t_addUnderNonExistingDir();
        print("\n");
        RemoveTester.t_removeDirTree();
        print("\n");
        RemoveTester.t_removeNonExisting();
        print("\n");
        RemoveTester.t_removeFile();
        print("\n");
        RemoveTester.t_removeNonExistingFile();
        print("\n");
        t_searchTest();
        print("\n");
        t_searchForNonExistingKeyTest();
        print("\n");
    }

    public static void t_searchTest() {
        print("Test: Searching a keyword in filesystem\n");
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
        print("Searching for keyword 'new', it will return a list of path strings:\n");
        List<String> list = myFileSystem.search("new");
        for(int i = 0; i < list.size(); i++) {
            print(list.get(i) + "\n");
        }
    }

    public static void t_searchForNonExistingKeyTest() {
        print("Test: Searching a keyword in filesystem, that does not exist\n");
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
        print("Searching for keyword 'CSE', it will return a empty list:\n");
        List<String> list = myFileSystem.search("CSE");
        for(int i = 0; i < list.size(); i++) {
            print(list.get(i) + "\n");
        }
    }

    
}