import java.util.Random;

/**
 * Generates random data
 */
public class Generator {

    /**
     * Generates random integer array with given size
     * 
     * @param size size of array
     * @param isSorted sorted or not
     * @return generated array
     */
    public static Integer[] generateArr(int size, boolean isSorted) {
        Integer[] arr = new Integer[size];
        if(isSorted) {
            int count = -size/2;
            for (int i = 0; i < arr.length; i++) {
                arr[i] = count;
                count++;
            }
            return arr;    
        }
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            int num = rand.nextInt(size);
            arr[i] = num;
        }
        return arr;
    }
}