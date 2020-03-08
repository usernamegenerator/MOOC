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

public class WordCount {
    public static void main(String[] args) {
        int writeSpaceCount = 0;
        while (!StdIn.isEmpty()) {
            String s = StdIn.readString();
            writeSpaceCount++;
        }
        StdOut.println("number of words =  " + writeSpaceCount);
    }
}
