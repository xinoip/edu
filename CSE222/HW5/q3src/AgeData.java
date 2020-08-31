
/**
 * AgeData contains ages with the populations
 */
public class AgeData implements Comparable<AgeData> {
    private int age;
    private int count;

    /**
     * Create AgeData with count of 1 and given age
     * 
     * @param age age to create
     */
    AgeData(int age) {
        this.age = age;
        count = 1;
    }

    /**
     * String info for age and count
     */
    @Override
    public String toString() {
        return Integer.toString(age) + "-" + Integer.toString(count); 
    }

    /**
     * Getter count
     * @return the count
     */
    public int getCount() {
        return count;
    }

    /**
     * Getter age
     * @return the age
     */
    public int getAge() {
        return age;
    }

    /**
     * Increment the count by one
     */
    public void increment() {
        count++;
    }

    /**
     * Decrement the count by one
     */
    public void decrement() {
        count--;
    }

    /**
     * Compare the AgeDatas by the age
     */
    @Override
    public int compareTo(AgeData o) {
        return age - o.age;
    }

}