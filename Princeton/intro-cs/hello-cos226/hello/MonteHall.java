/******************************************************************************
 * 
 * Game simulation. In the game show Let's Make a Deal, a contestant is presented with three doors. 
 * Behind one door is a valuable prize, behind the other two are gag gifts. 
 * After the contestant chooses a door, the host opens up one of the other two doors (never revealing the prize, of course). 
 * The contestant is then given the opportunity to switch to the other unopened door. 
 * Should the contestant do so? Intuitively, 
 * it might seem that the contestant's initial choice door and the other unopened door are equally likely to contain the prize, 
 * so there would be no incentive to switch. Write a program MonteHall.java to test this intuition by simulation. 
 * Your program should take an integer command-line argument n, 
 * play the game n times using each of the two strategies (switch or don't switch) 
 * and print the chance of success for each strategy. Or you can play the game here.
 * 
 * 
 * 
 *  Compilation:  javac MonteHall.java
 *  Execution:    java MonteHall trials
 *  
 *  Plays the Monte Hall game the specified number of times with the
 *  switching strategy and reports the fraction of games won.
 *
 *  Sample execution:
 *
 * % java MonteHall 10000000
 * Fraction of games won = 0.666586
 *
 *
 *  Note:  true winning probability = 2/3.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class MonteHall {
    public static void main(String[] args){
        int n = (int)(Math.random()*1000000) + 1; // +1 to avoid 0
        System.out.println("play the game " + n + " times");
        int win = 0;
        //simulate switch strategy 
        for (int i = 0 ; i<n; i++){
            //set a hidden price
            int price_door = (int)(Math.random()*3);

            //player pick a door, hidden
            int first_guess_door = (int)(Math.random()*3);
            
            //host reveal a door, not to reveal the price door and also the first guess door
            int reveal_door;
            do{
                reveal_door = (int)(Math.random()*3);
            }while(reveal_door == price_door || reveal_door == first_guess_door); 
            
            //player switch, not to switch to the reveal door
            int second_guess_door;
            do{
                second_guess_door = (int)(Math.random()*3);
            }while(second_guess_door == reveal_door || second_guess_door == first_guess_door);
            
            //check results
            if(second_guess_door == price_door){
                win++;
            }
        }
        System.out.println("win = " + win);
        System.out.println("chance to win = " + (double)(win)/(double)(n));
    }
}
