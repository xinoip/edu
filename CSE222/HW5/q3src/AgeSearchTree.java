
/**
 * AgeSearchTree is a BST Structure for searching AgeData
 */
public class AgeSearchTree extends BinarySearchTree<AgeData> {

    /**
     * Adding given AgeData to tree
     * It will increment the existing AgeData, if non existent then create it
     * 
     * @param item AgeData to add
     */
    @Override
    public boolean add(AgeData item) {
        AgeData found = find(item);

        if (found != null) {
            found.increment();
            return true;
        } else {
            return super.add(item);
        }
    }

    /**
     * Remove given AgeData from tree
     * It will decrement the existing AgeData and if the count hits 0 after that
     * It will remove it
     * 
     * @param target target to remove
     */
    @Override
    public boolean remove(AgeData target) {
        AgeData found = find(target);
        if (found == null) {
            return false;
        }

        if (found.getCount() > 1) {
            found.decrement();
            return true;
        } else {
            return super.remove(target);
        }
    }

    /**
     * Finds and returns the given target
     * if not found, return null
     * 
     * @param target target to search for
     */
    @Override
    public AgeData find(AgeData target) {
        return super.find(target);
    }

    /**
     * Recursive solution for youngerThan
     * 
     * @param root start node
     * @param age target age
     * @return count of younger than the given age
     */
    private int youngerThanHelper(Node<AgeData> root, int age) {
        int count = 0;

        if (root == null) {
            return 0;
        } else if (root.data.getAge() < age) {
            count += root.data.getCount();
            count += youngerThanHelper(root.left, age);
            count += youngerThanHelper(root.right, age);
        } else {
            count += youngerThanHelper(root.left, age);
        }

        return count;
    }

    /**
     * Count the people younger than given age
     * 
     * @param age target age
     * @return count of people
     */
    public int youngerThan(int age) {
        return youngerThanHelper(root, age);
    }

    /**
     * Count the people younger than given age
     * 
     * @param age target age
     * @return count of people
     */
    public int olderThan(int age) {
        return olderThanHelper(root, age);
    }

    /**
     * Recursive solution for olderThan
     * 
     * @param root start node
     * @param age target age
     * @return count of older than the given age
     */
    public int olderThanHelper(Node<AgeData> root, int age) {
        int count = 0;

        if (root == null) {
            return 0;
        } else if (root.data.getAge() > age) {
            count += root.data.getCount();
            count += olderThanHelper(root.left, age);
            count += olderThanHelper(root.right, age);
        } else {
            count += olderThanHelper(root.right, age);
        }

        return count;
    }
}