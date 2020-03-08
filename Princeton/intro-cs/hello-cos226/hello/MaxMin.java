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

public class MaxMin {
    public static void main(String[] args) {
        int max = StdIn.readInt();
        int min = max;
        int i;

        while (!StdIn.isEmpty()) {
            i = StdIn.readInt();
            if (i > max) {
                max = i;
            }
            if (i < min) {
                min = i;
            }
        }

        StdOut.println("min " + min + " max " + max);
    }
}
