
/**
 * Helper class for utilities
 */
public class Helper {

    /**
     * Reverse the given sentence, word wise
     * 
     * @param str sentence to reverse
     * @return reversed sentence
     */
    public static String reverse(String str) {
        if (str == null)
            return null;

        int n = str.indexOf(' ');
        if (n == -1)
            return str;

        String reversed = reverse(str.substring(n + 1));
        if (reversed != null)
            return reversed + " " + str.substring(0, n);
        else
            return str;
    }

    /**
     * Check if the given character is digit or not
     * 
     * @param c char to check
     * @return true if it is a digit, false otherwise
     */
    public static boolean isDigit(char c) {
        return c >= 48 && c <= 57;
    }
}