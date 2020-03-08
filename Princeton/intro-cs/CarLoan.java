/******************************************************************************
 *  Compilation:  javac CarLoan.java
 *  Execution:    java CarLoan principal years rate
 *
 *  Calculate the monthly payments if you take out a $principal loan for
 *  the specified number of years at the specified interest rate,
 *  where interested is compounded monthly.
 *
 *                  principal * rate
 *     payment =  -------------------      where n = 12 * years,
 *                1  - (1 + r)^(-n)              r = (rate / 100) / 12
 *
 *
 *  % java CarLoan 20000 5 6
 *  Monthly payments = 386.6560305885655
 *  Total interest   = 3199.361835313932
 *
 *
 *  Bugs
 *  ----
 *  Does not work if rate = 0% interest. Easy to fix if you know about
 *  if-else statements.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author ssdrive
 *  *  % java CarLoan 20000 5 6
 *  Monthly payments = 386.6560305885655
 *  Total interest   = 3199.361835313932
 */
public class CarLoan {
    public static void main(String[] args){
        double P = 20000;
        int Y = 5;
        double R = 6;
        double n = 12 * Y;
        double r = (R/100)/12;
        
        double payment = (P * r) / ( 1 - Math.pow(1+r,-n));
        System.out.println("Monthly payments = " + payment);
             
    }
}
