/******************************************************************************
 *  Compilation:  javac FivePerLine.java
 *  Execution:    java FivePerLine
 *  
 *  Print the integers from 1000 to 2000, 5 per line.
 *
 *  % java FivePerLine
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class FivePerLine {
    public static void main(String[] args){
        for (int i = 1000; i<=2000;i++){
            System.out.print(i + " ");
            if(i%5==4)
                System.out.println();
        }
    }
}
