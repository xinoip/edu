import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.AbstractList;
import java.util.List;
import java.util.ListIterator;

/**
 * SimpleTextEditor is a text container which uses AbstractList to hold characters
 */
public class SimpleTextEditor {

    /**
     * Represented data
     */
    private AbstractList<Character> list;

    /**
     * User can inject any AbstractList to SimpleTextEditor
     *
     * @param list data to represent with
     */
    public SimpleTextEditor(AbstractList<Character> list) {
        this.list = list;
    }

    /**
     * Lists toString
     *
     * @return lists toString
     */
    @Override
    public String toString() {
        String rtr = "";

        rtr = list.toString();

        return rtr;
    }

    /**
     * Open and read the given filename, with loops.
     *
     * @param fileName file to read
     */
    public void readLoop(String fileName) {
        try {
            File file = new File(fileName);

            BufferedReader br = new BufferedReader(new FileReader(file));

            list.clear();

            int c = 0;
            while((c = br.read()) != -1)
            {
                char character = (char) c;
                list.add(character);
            }
        } catch (Exception e) {
            System.err.println("IO Error occurred!");
        }
    }

    /**
     * Insert given string to given index with loops
     *
     * @param index position to insert
     * @param str element to insert
     */
    public void addLoop(int index, String str) {

        for(int i = 0; i < str.length(); i++) {
            list.add(i + index, str.charAt(i));
        }

    }

    /**
     * Find given string with loops
     *
     * @param str string to find
     * @return position of found string
     */
    public int findLoop(String str) {

        for(int i = 0; i < list.size() - str.length(); i++) {

            List<Character> currList = list.subList(i, i + str.length());
            String currStr = "";

            for (Character character : currList) {
                currStr += character;
            }

            if(currStr.equals(str)) {
                return i;
            }

        }

        return -1;
    }

    /**
     * Replace all target characters with given replacement using loops
     *
     * @param target target to replace
     * @param replacement replacement character
     */
    public void replaceLoop(char target, char replacement) {

        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).equals(target)) {
                list.set(i, replacement);
            }
        }

    }

    /**
     * Open and read the given filename, with ListIterator.
     *
     * @param fileName file to read
     */
    public void readIter(String fileName) {
        try {
            File file = new File(fileName);

            BufferedReader br = new BufferedReader(new FileReader(file));

            list.clear();

            ListIterator<Character> iterator = list.listIterator();

            int c = 0;
            while((c = br.read()) != -1)
            {
                char character = (char) c;

                iterator.add(character);
            }
        } catch (Exception e) {
            System.err.println("IO Error occurred!");
        }
    }

    /**
     * Insert given string to given index with ListIterator
     *
     * @param index position to insert
     * @param str element to insert
     */
    public void addIter(int index, String str) {

        ListIterator<Character> iterator = list.listIterator(index);

        for(int i = 0; i < str.length(); i++) {
            iterator.add(str.charAt(i));
        }

    }

    /**
     * Find given string with ListIterator
     *
     * @param str string to find
     * @return position of found string
     */
    public int findIter(String str) {

        ListIterator<Character> iterator = list.listIterator(0);

        for(int i = 0; i < list.size() - str.length(); i++) {

            String currStr = "";
            int limit = i + str.length();
            for(int j = i; j < limit; j++) {
                char currChar = iterator.next();
                currStr += currChar;
            }

            iterator = list.listIterator(i);
            if(currStr.equals(str)) {
                return i;
            }

        }

        return -1;
    }

    /**
     * Replace all target characters with given replacement using ListIterator
     *
     * @param target target to replace
     * @param replacement replacement character
     */
    public void replaceIter(char target, char replacement) {

        ListIterator<Character> iterator = list.listIterator(0);

        for(int i = 0; i < list.size(); i++) {
            char currentChar = iterator.next();

            if(currentChar == target) {
                iterator.set(replacement);
            }
        }

    }

}
