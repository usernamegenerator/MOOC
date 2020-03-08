/******************************************************************************
 *  Compilation:  javac AllEqual.java
 *  Execution:    java AllEqual a b c
 *
 *  Prints "equal" if a = b = c and "not equal" otherwise.
 *
 *  % java AllEqual 10 10 10
 *  all equal
 *
 *  % java AllEqual 10 20 10
 *  not all equal
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author ssdrive
 */
public class AllEqual {
    public static void main(String[] args){
        int a = (int)(Math.random()*5);
        int b = (int)(Math.random()*5);
        int c = (int)(Math.random()*5);
        
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        if (a==b && b==c){
            System.out.println("equal");
        }
        else{
            System.out.println("not all equal");
        }
    }
}
