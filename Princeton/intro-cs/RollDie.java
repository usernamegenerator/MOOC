/******************************************************************************
 *  Compilation:  javac RollDie.java
 *  Execution:    java RollDie
 *
 *  Simulate the roll of a fair six-sided die
 *  and print the resulting number.
 *
 *  % java RollDie
 *  4
 *
 *  % java RollDie
 *  1
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class RollDie {
    public static void main(String[] args){
        for(int n = 0 ; n < 10000; n++){
            int roll = (int)(Math.random()*6)+1;
            //System.out.println(roll);
            if(roll<1 || roll>6){
                System.out.println("error");
            }
        }
    }
}
