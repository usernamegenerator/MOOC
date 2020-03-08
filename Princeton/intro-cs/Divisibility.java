/******************************************************************************
 *  Compilation:  javac Divisibility.java
 *  Execution:    java Divisibility x y
 *  
 *  Reads in two integer command-line arguments x and y and prints "true"
 *  if both are divisible by 7, and false otherwise.
 *
 *  % java Divisibility 14 21
 *  true
 *
 *  % java Divisibility 4 21
 *  false
 * 
 *  % java Divisibility 100 200
 *  false
 *
 *  a % 7 is the remainder when you divide 7 into a. If the remainder
 *  is 0, then a is divisible by 7.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author ssdrive
 */
public class Divisibility {
    public static void main(String[] args){
        int a = (int)(Math.random()*100);
        int b = (int)(Math.random()*100);
        System.out.println(a);
        System.out.println(b);
        if(a%7==0 && b%7==0){
            System.out.println("true");
        }
        else{
            System.out.println("false");
        }
    }
}
