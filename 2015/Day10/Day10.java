import java.lang.StringBuilder;
import java.io.UnsupportedEncodingException;

public class Day10 {
    public static void main(String[] args) throws UnsupportedEncodingException {
        String in = args[0];
        for (int i = 0; i < Integer.parseInt(args[1]); i++) {
            in = lookAndSay(in);
        }
        System.out.println("The length of the result is " + in.length());
    }

    // Perforn the look-and-say algorithm on a string, getting a new string.
    static public String lookAndSay(String in) {
        StringBuilder next = new StringBuilder();
        char lastChar = in.charAt(0);
        int lastCharCount = 1;
        for (int i = 1; i < in.length(); i++) {
            char c = in.charAt(i);
            if (c == lastChar) {
                lastCharCount++;
            }
            else {
                next.append(lastCharCount);
                next.append(lastChar);
                lastChar = c;
                lastCharCount = 1;
            }
        }
        next.append(lastCharCount);
        next.append(lastChar);
        return next.toString();
    }
}
