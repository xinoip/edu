import java.nio.file.FileSystemException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * FileSystemTree is a GeneralTree structure that represents a file system
 */
public class FileSystemTree {

    /**
     * Root of the tree
     */
    private FileNode root;

    /**
     * Constructor to create a tree with a root directory
     *
     * @param rootDirName root directory name
     */
    FileSystemTree(String rootDirName) {
        root = new FileNode(rootDirName, true);
        root.path = "root";
    }

    /**
     * The node class for GeneralTree structure
     * This represents the members of the FileSystem
     */
    private class FileNode {
        /**
         * The name of the File/Folder
         */
        public String name;

        /**
         * FullPath of the File/Folder
         */
        public String path;

        /**
         * isDir flag used to differentiate directories from files
         */
        public boolean isDir;

        /**
         * Every node can have any number of children
         */
        public List<FileNode> children;

        /**
         * Constructor for creating a FileNode with given name and given flag
         * Depending on given flag it creates a File or Folder
         *
         * @param name new File/Folder name
         * @param isDir is it File or is it Folder
         */
        FileNode(String name, boolean isDir) {
            this.name = name;
            this.children = new ArrayList<>();
            this.isDir = isDir;
        }

        /**
         * Check if the node has a child with given name
         *
         * @param name child to search for
         * @return childs index, -1 if not found
         */
        public int hasChild(String name) {
            for(int i = 0; i < children.size(); i++) {
                if(children.get(i).name.equals(name)) {
                    return i;
                }
            }
            return -1;
        }

        /**
         * Add the given FileNode as a new child of this node
         *
         * @param node new child
         * @return success status
         */
        public boolean addChild(FileNode node) {
            if(!isDir) {
                return false;
            }

            children.add(node);
            return true;
        }
    }

    /**
     * Try to add new directory at given path
     * If the path is valid and all, it will create the directory
     * Otherwise, it will throw a FileSystemException
     *
     * @param path new path to create
     * @throws FileSystemException throws on error
     */
    public void addDir(String path) throws FileSystemException {
        String[] parts = path.split("/");

        FileNode nodePtr = root;

        for (int i = 0; i < parts.length; i++) {
            String currentPart = parts[i];
            if (i == parts.length - 2) {
                // try to place it
                if (nodePtr.hasChild(parts[i + 1]) != -1) {
                    throw new FileSystemException(path);
                }

                FileNode newFile = new FileNode(parts[i + 1], true);
                newFile.path = path;
                boolean result = nodePtr.addChild(newFile);

                if (!result)
                    throw new FileSystemException(path);

                return;
            } else {
                if (!nodePtr.isDir) {
                    throw new FileSystemException(path);
                }

                if (currentPart.equals(nodePtr.name)) {
                    int childResult = nodePtr.hasChild(parts[i + 1]);
                    if (childResult == -1) {
                        throw new FileSystemException(path);
                    } else {
                        nodePtr = nodePtr.children.get(childResult);
                    }
                }
            }
        }
    }

    /**
     * Try to add new file at given path
     * If the path is valid and all, it will create the file
     * Otherwise, it will throw a FileSystemException
     *
     * @param path new path to create
     * @throws FileSystemException throws on error
     */
    public void addFile(String path) throws FileSystemException {
        String[] parts = path.split("/");

        FileNode nodePtr = root;

        for (int i = 0; i < parts.length; i++) {
            String currentPart = parts[i];
            if (i == parts.length - 2) {
                // try to place it
                if (nodePtr.hasChild(parts[i + 1]) != -1) {
                    throw new FileSystemException(path);
                }

                FileNode newFile = new FileNode(parts[i + 1], false);
                newFile.path = path;
                boolean result = nodePtr.addChild(newFile);

                if (!result)
                    throw new FileSystemException(path);

                return;
            } else {
                if (!nodePtr.isDir) {
                    throw new FileSystemException(path);
                }

                if (currentPart.equals(nodePtr.name)) {
                    int childResult = nodePtr.hasChild(parts[i + 1]);
                    if (childResult == -1) {
                        throw new FileSystemException(path);
                    } else {
                        nodePtr = nodePtr.children.get(childResult);
                    }
                }
            }
        }
    }

    /**
     * Remove File/Folder at given path
     * If the path is valid and all, it will remove.
     * If the FileNode at path is directory and contains other children, then it will prompt the user with a yes/no
     *
     * @param path path to delete
     * @throws FileSystemException throw on error
     */
    public void remove(String path) throws FileSystemException {
        String[] parts = path.split("/");

        FileNode nodePtr = root;

        for (int i = 0; i < parts.length; i++) {
            String currentPart = parts[i];
            if (i == parts.length - 2) {
                if (nodePtr.hasChild(parts[i + 1]) != -1) {
                    for (FileNode child : nodePtr.children) {
                        if (child.name.equals(parts[i + 1])) {
                            if (child.children.isEmpty()) {
                                nodePtr.children.remove(child);
                            } else {
                                System.out.println(child.name + " is not empty!");
                                System.out.println("Contents of " + child.name + ": ");
                                printHelper(child, 1);
                                Scanner sc = new Scanner(System.in);
                                System.out.print("Delete anyway? (y/n): ");
                                String input = sc.next();
                                if (input.equals("y")) {
                                    nodePtr.children.remove(child);
                                    System.out.println(child.name + " deleted!");
                                } else {
                                    System.out.println(child.name + " deletion aborted!");
                                }
                                sc.close();
                            }
                            return;
                        }
                    }
                } else {
                    throw new FileSystemException(path);
                }
            } else {
                if (currentPart.equals(nodePtr.name)) {
                    int childResult = nodePtr.hasChild(parts[i + 1]);
                    if (childResult == -1) {
                        throw new FileSystemException(path);
                    } else {
                        nodePtr = nodePtr.children.get(childResult);
                    }
                }
            }
        }
    }

    /**
     * Recursive solution for searching a keyword in FileSystemTree
     * It will start from given root and search for given searchStr
     * Every time it found any path with given key, populate the list.
     *
     * @param root node to search from
     * @param list an empty list for recursively passing
     * @param searchStr keyword to search
     */
    private void searchHelper(FileNode root, ArrayList<String> list, String searchStr) {
        if (root.name.contains(searchStr)) {
            String str = "";
            if (root.isDir) {
                str += "dir - ";
            } else {
                str += "file - ";
            }
            str += root.path;
            list.add(str);
        }
        for (FileNode child : root.children) {
            searchHelper(child, list, searchStr);
        }
    }

    /**
     * Search the given keyword in FileSystemTree.
     * It will return a list of Strings with the words containing that keyword.
     *
     * @param str keyword to search for
     * @return found words that contains keyword
     */
    public ArrayList<String> search(String str) {
        ArrayList<String> rtr = new ArrayList<>();
        searchHelper(root, rtr, str);
        return rtr;
    }

    /**
     * Recursive solution for printing the FileSystemTree
     * It will print from given Node.
     *
     * @param root printing start
     * @param level initial depth of FileSystemTree for the start
     */
    private void printHelper(FileNode root, int level) {
        for (int i = 1; i < level; i++) {
            if (i == level - 1) {
                System.out.print("----");
            } else {
                System.out.print("    ");
            }
        }
        System.out.println(root.name);
        for (FileNode child : root.children) {
            printHelper(child, level + 1);
        }
    }

    /**
     * Prints the FileSystemTree
     */
    public void printFileSystem() {
        printHelper(root, 1);
    }
}