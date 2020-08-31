import java.util.LinkedList;
import java.util.Random;

public class Generator {

    public static LinkedList<Integer> generateLL(int size, boolean isSorted) {
        LinkedList<Integer> list = new LinkedList<>();
        if(isSorted) {
            for (int i = -(size/2); i < size/2; i++) {
                list.add(i);
            }
            return list;    
        }
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            int num = rand.nextInt(1000);
            list.add(num);
        }
        return list;
    }

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
            int num = rand.nextInt(1000);
            arr[i] = num;
        }
        return arr;
    }

}