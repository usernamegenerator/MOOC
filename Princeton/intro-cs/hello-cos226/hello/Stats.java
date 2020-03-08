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

public class Stats {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int i = 0;
        double[] numbers = new double[n];
        double sum = 0;
        double ave = 0;
        double u;
        while (i < n) {
            numbers[i] = StdIn.readDouble();
            sum += numbers[i];
            i++;
        }
        ave = sum / n;

        double temp = 0.0;
        for (int j = 0; j < n; j++) {
            temp += (numbers[j] - ave) * (numbers[j] - ave);
        }
        u = Math.sqrt(temp / (n - 1));
        StdOut.println("sum " + sum + " ave " + ave + " u " + u);
    }
}
