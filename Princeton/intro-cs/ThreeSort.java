/******************************************************************************
 *  Compilation:  javac ThreeSort.java
 *  Execution:    java ThreeSort a b c
 *  
 *  Read 3 integer values from the command line and print them
 *  in ascending order.
 *
 *  % java ThreeSort 17 50 33
 *  17
 *  33
 *  50
 *
 *  % java ThreeSort 50 33 17
 *  17
 *  33
 *  50
 *
 *  % java ThreeSort 17 50 17
 *  17
 *  17
 *  50
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class ThreeSort {
    public static void main(String[] args){
        double one = Math.random();
        double two = Math.random();
        double three = Math.random();
        
        System.out.println("three numbers");
        System.out.println(one);
        System.out.println(two);
        System.out.println(three);
        
        
        double temp = Math.max(one, two);
        double max = Math.max(temp,three);
        
        temp = Math.min(one,two);
        double min = Math.min(temp,three);
        
        System.out.println("min = " + min);
        System.out.println("max = " + max);
    }
            
}
