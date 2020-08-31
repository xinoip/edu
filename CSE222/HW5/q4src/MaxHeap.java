import java.util.ArrayList;
import java.util.Comparator;

/**
 * Custom MaxHeap implementation, primarly for AgeData
 * 
 * @param <E> AgeData
 */
public class MaxHeap<E extends AgeData> {

    /**
     * Representing heap as Arraylist
     */
    private ArrayList<E> heap;

    /**
     * Comparator for heapm ordering
     */
    private Comparator<E> comp;

    /**
     * Creates empty heap
     */
    public MaxHeap() {
        heap = new ArrayList<>();
        comp = new AgeDataHeapComparator<>();
    }

    /**
     * Find the parent of the element at given index
     * 
     * @param index element position
     * @return parent of element
     */
    private E parent(int index) {
        return heap.get(parentPos(index));
    }

    /**
     * Find the left child of the element at given index
     * 
     * @param index element position
     * @return left child of element
     */
    private E leftChild(int index) {
        return heap.get(leftChildPos(index));
    }

    /**
     * Find the right child of the element at given index
     * 
     * @param index element position
     * @return right child of element
     */
    private E rightChild(int index) {
        return heap.get(rightChildPos(index));
    }

    /**
     * Find the parents index of the element at given index
     * 
     * @param index element position
     * @return index of parent of element
     */
    private static int parentPos(int index) {
        return (index - 1) / 2;
    }

    /**
     * Find the left childs index of the element at given index
     * 
     * @param index element position
     * @return index of left child of element
     */
    private static int leftChildPos(int index) {
        return 2 * index + 1;
    }

    /**
     * Find the right childs index of the element at given index
     * 
     * @param index element position
     * @return index of right child of element
     */
    private static int rightChildPos(int index) {
        return 2 * index + 2;
    }

    /**
     * Swap in heap within the given indexes
     * 
     * @param x index to swap
     * @param y index to swap
     */
    private void swap(int x, int y) {
        E tmp = heap.get(x);
        heap.set(x, heap.get(y));
        heap.set(y, tmp);
    }

    /**
     * Find the given item in heap
     * Return item or null
     * 
     * @param item item to search for
     * @return found item or null
     */
    public E find(E item) {
        for (E element : heap) {
            if (element.compareTo(item) == 0) {
                return element;
            }
        }

        return null;
    }

    /**
     * Add the given item to heap
     * 
     * @param item item to add
     */
    public void add(E item) {
        E found = find(item);

        if (found != null) {
            found.increment();
        } else {
            int itemPosition = heap.size();
            heap.add(item);
            while (itemPosition != 0 && comp.compare(item, parent(itemPosition)) > 0) {
                swap(itemPosition, parentPos(itemPosition));
                itemPosition = parentPos(itemPosition);
            }
        }
    }

    /**
     * Fix the heap structure from given index
     * 
     * @param index start index
     */
    private void fixHeapFrom(int index) {
        E current = heap.get(index);

        if(leftChildPos(index) < 0 || leftChildPos(index) >= heap.size() || rightChildPos(index) < 0 || rightChildPos(index) >= heap.size()) {
            return;
        }
        if (comp.compare(current, leftChild(index)) < 0 || comp.compare(current, rightChild(index)) < 0) {

            int compResult = comp.compare(leftChild(index), rightChild(index));

            if (compResult > 0) {
                swap(index, leftChildPos(index));
                fixHeapFrom(leftChildPos(index));
            } else if (compResult < 0) {
                swap(index, rightChildPos(index));
                fixHeapFrom(rightChildPos(index));
            }
        }
    }

    /**
     * Find and remove the given target from heap
     * 
     * @param target target to remove
     */
    public void remove(E target) {
        int index = -1;
        E found = null;
        for (int i = 0; i < heap.size(); i++) {
            E current = heap.get(i);
            if (current.compareTo(target) == 0) {
                found = current;
                index = i;
                break;
            }
        }

        if (index == -1) {
            return;
        }

        if (found.getCount() > 1) {
            found.decrement();
        } else {
            swap(index, heap.size() - 1);
            heap.remove(heap.size() - 1);
        }

        fixHeapFrom(index);
    }

    /**
     * Find count of people younger than given age
     * 
     * @param age target age
     * @return people count
     */
    public int youngerThan(int age) {
        int count = 0;

        for(E element : heap) {
            if(element.getAge() < age) {
                count += element.getCount();
            }
        }

        return count;
    }

    /**
     * Find count of people older than given age
     * 
     * @param age target age
     * @return people count
     */
    public int olderThan(int age) {
        int count = 0;

        for(E element : heap) {
            if(element.getAge() > age) {
                count += element.getCount();
            }
        }

        return count;
    }

    /**
     * Heap structure as string
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(E element : heap) {
            sb.append(element.toString() + "\n");
        }
        return sb.toString();
    }
}