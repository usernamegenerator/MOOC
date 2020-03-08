/* *****************************************************************************
 *  Name:    Alan Turing
 *  NetID:   aturing
 *  Precept: P00
 *
 *  Partner Name:    Ada Lovelace
 *  Partner NetID:   alovelace
 *  Partner Precept: P00
 *
 *  Description:  Prints 'Hello, World' to the terminal window.
 *                By tradition, this is everyone's first program.
 *                Prof. Brian Kernighan initiated this tradition in 1974.
 *
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class LongestRun {
    public static void main(String[] args) {
        int pre = StdIn.readInt();
        int count = 1;
        int maxCount = 1;
        int consecutive = pre;
        int cur = pre;

        while (!StdIn.isEmpty()) {
            cur = StdIn.readInt();
            if (cur == pre) {
                count++;
                if (count > maxCount) {
                    consecutive = cur;
                    maxCount = count;
                }
            }
            else {
                count = 1;
            }
            pre = cur;
        }

        StdOut.println("Longest run: " + maxCount + " consecutive " + consecutive + "s");
    }
}
