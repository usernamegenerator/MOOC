/******************************************************************************
 *  Compilation:  javac TenHelloWorlds.java
 *  Execution:    java TenHelloWorlds
 *
 *  Prints "Hello, World" ten times. You'll learn about a more
 *  compact way to do this in Section 1.3 when we introduce loops.
 *
 *  % java TenHelloWorlds
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *  Hello, World
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhangli
 */
public class TenHelloWorlds {
    public static void main(String[] args){
        int i;
        for (i=0;i<10;i++){
            System.out.println("Hello, World");
        }
    }
}
