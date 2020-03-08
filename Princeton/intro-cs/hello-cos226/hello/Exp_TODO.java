/******************************************************************************
 * 
 * Exponential function. Assume that x is a positive variable of type double. Write a program Exp.java that computes e^x using the Taylor series expansion

* 
* 
 *  Compilation:  javac Exp.java
 *  Execution:    java Sin x
 *  
 *  Prints out e^x using Taylor expansion.
 *  
 *     e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! + ..
 *
 *  % java Exp 1.0
 *  1.0
 *  1.0
 *
 *  % java Exp 1
 *  2.7182818284590455
 *  2.7182818284590455
 *
 *  % java Exp 10
 *  22026.465794806718
 *  22026.465794806714
 *
 *  % java Exp -10
 *  4.539992976248485E-5
 *  4.5399929762484854E-5
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class Exp_TODO {
    public static void main(String[] args){
        int x = (int)(Math.random()*10 - 5);
        System.out.println(x);
        double res = Math.exp(x);
        System.out.println(res);
        
        double sum = 1;
        double term = 1;
        
        
        }
    }
