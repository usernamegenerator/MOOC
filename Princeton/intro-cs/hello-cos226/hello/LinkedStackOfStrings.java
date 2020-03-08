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

import java.util.NoSuchElementException;

public class LinkedStackOfStrings {
    private Node first;
    private int size;


    public LinkedStackOfStrings() {
        first = null;
        size = 0;
    }


    private class Node {
        private String item;
        private Node next;
    }

    public void push(String item) {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        size++;
    }

    public String pop() {
        if (isEmpty()) throw new NoSuchElementException("stack underflow");
        String item = first.item;
        first = first.next;
        size--;
        return item;
    }

    public boolean isEmpty() {
        return first == null;
    }


    public static void main(String[] args) {
        LinkedStackOfStrings stack = new LinkedStackOfStrings();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) stack.push(item);
            else if (stack.isEmpty()) StdOut.println("BAD INPUT");
            else StdOut.print(stack.pop());
        }
    }

}
