/******************************************************************************
 *  Compilation:  javac Ramanujan.java
 *  Execution:    java Ramanujan n
 *  
 *  Prints out any number between 1 and n that can be expressed as the
 *  sum of two cubes in two (or more) different ways.
 *
 *  % java Ramanujan 1728
 *
 *  % java Ramanujan 1729
 *  1729 = 1^3 + 12^3 = 9^3 + 10^3
 *
 *  % java Ramanujan 10000
 *  1729 = 1^3 + 12^3 = 9^3 + 10^3
 *  4104 = 2^3 + 16^3 = 9^3 + 15^3
 *
 *  % java Ramanujan 100000
 *  1729 = 1^3 + 12^3 = 9^3 + 10^3
 *  4104 = 2^3 + 16^3 = 9^3 + 15^3
 *  13832 = 2^3 + 24^3 = 18^3 + 20^3
 *  39312 = 2^3 + 34^3 = 15^3 + 33^3
 *  46683 = 3^3 + 36^3 = 27^3 + 30^3
 *  32832 = 4^3 + 32^3 = 18^3 + 30^3
 *  40033 = 9^3 + 34^3 = 16^3 + 33^3
 *  20683 = 10^3 + 27^3 = 19^3 + 24^3
 *  65728 = 12^3 + 40^3 = 31^3 + 33^3
 *  64232 = 17^3 + 39^3 = 26^3 + 36^3
 *
 *  % java Ramanujan 100000000 | sort -n   // sort results numerically in Unix
 *  1729 = 1^3 + 12^3 = 9^3 + 10^3
 *  ...
 *  87539319 = 167^3 + 436^3 = 228^3 + 423^3
 *  87539319 = 167^3 + 436^3 = 255^3 + 414^3
 *  87539319 = 228^3 + 423^3 = 255^3 + 414^3
 *  ...
 *
 *  Bugs
 *  ----
 *  If a number can be expressed as a sum of cubes in more than two
 *  different ways, the program prints some duplicates.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *System.out.printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n",i,a,b,c,d);
 * @author yuhan
 */
public class Ramanujan {
    public static void main(String[] args){
        //int n = (int)(Math.random()*10000);
        int i = 100000;
        //for (int i = 1 ; i < n ; i++){
            for (int a = 1 ; a <= i ; a++){
                if(a*a*a > i){
                    break;
                }
                for (int b = a + 1; b <= i ; b++){
                    if(b*b*b > i){
                        break;
                    }
                    //if (i==a*a*a+b*b*b){
                        //System.out.printf("ab %d = %d^3 + %d^3\n",i,a,b);
                        for(int c = a+1; c<=i; c++){
                            if(c*c*c > i){
                                break;
                            }
                            for(int d = c + 1; d<=i; d++){
                                //if (i==c*c*c+d*d*d){
                                if(d*d*d > i){
                                    break;
                                }
                                if(a*a*a + b*b*b == c*c*c + d*d*d){
                                    //System.out.printf("cd %d = %d^3 + %d^3\n",i,c,d);
                                    System.out.printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n",a*a*a+b*b*b,a,b,c,d);
                                }
                            }
                        }
                    //}
                }
            }
        //}
    }
}
