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

import edu.princeton.cs.algs4.StdDraw;

public class Checkerboard {
    public static void main(String[] args) {
        int n = 8;
        StdDraw.setXscale(0, n);
        StdDraw.setYscale(0, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 != 0) StdDraw.setPenColor(StdDraw.BLACK);
                else StdDraw.setPenColor(StdDraw.RED);
                StdDraw.filledSquare(i + 0.5, j + 0.5, 0.5);
            }
        }
    }
}
