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

public class ArrayStackOfStrings {
    private String items[];
    private int size;

    public ArrayStackOfStrings(int capacity) {
        items = new String[capacity];
        size = 0;
    }

    public void push(String s) {
        items[size++] = s;
    }

    public String pop() {
        return items[--size];

    }

    public boolean isEmpty() {
        return (size == 0);
    }

    public boolean isFull() {
        return (size == items.length);
    }

    public static void main(String[] args) {
        int capacity = Integer.parseInt(args[0]);
        ArrayStackOfStrings stack = new ArrayStackOfStrings(capacity);
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) {
                stack.push(item);
            }
            else {
                StdOut.print(stack.pop() + " ");
            }
        }
        StdOut.println();
    }
}
