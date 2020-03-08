/******************************************************************************
 *  Compilation:  javac RollLoadedDie.java
 *  Execution:    java RollLoadedDie
 *
 *  Simulate the roll of a loaded six-sided die, where the values
 *  1, 2, 3, 4, and 5 appear with probability 1/8 and the value 6
 *  appears with probablity 3/8, and print the resulting number.
 *
 *  % java RollLoadedDie
 *  4
 *
 *  % java RollLoadedDie
 *  6
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author ssdrive
 */
public class RollLoadedDie {
    public static void main(String[] args){
        int roll = (int)(Math.random()*7);
        if (roll==5 || roll==6 || roll==7){
            System.out.println("6");
        }
        else{
            System.out.println(roll+1);
        }
    }
}
