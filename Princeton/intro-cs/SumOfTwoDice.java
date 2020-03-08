/******************************************************************************
 *  Compilation:  javac SumOfTwoDice.java
 *  Execution:    java SumOfTwoDice
 *  
 *  Generate 2 integers between 1 and 6, and print their sum.
 * 
 *  %  java SumOfTwoDice
 *  5
 *
 *  %  java SumOfTwoDice
 *  9
 *
 *  %  java SumOfTwoDice
 *  3
 *
 *  %  java SumOfTwoDice
 *  11
 *
 *  %  java SumOfTwoDice
 *  8
 *
 *  %  java SumOfTwoDice
 *  7
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class SumOfTwoDice {
    public static void main(String[] args){
        double x = Math.random();
        double y = Math.random();
        int x_prime =(int)(x*6);
        int y_prime =(int)(y*6);
        
        System.out.println(x_prime+y_prime);
        
    }
}
