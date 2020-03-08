/******************************************************************************
 *  Compilation:  javac ISBN.java
 *  Execution:    java ISBN n
 *  
 *  Determines the check digit of an ISBN number given the first 9 digits.
 *
 *  An ISBN number is legal if it consists of 10 digits and
 *  d_1 + 2*d_2 + 3*d_3 + ... + 10*d_10 is a multiple of 11.
 *  For example, 0-201-31452-5 is legal since
 *  1*5 + 2*2 + 3*5 + 4*4 + 5*1 + 6*3 + 7*1 + 8*0 + 9*2 + 10*0 = 88
 *  and 88 is a multiple of 11.
 *
 *  Sample execution:
 *
 *       % java ISBN 020131452
 *       The full ISBN number is 201314525.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class ISBN {
    public static void main(String[] args){
        // lesson learned, in java, an int start with 0 means octal number
        //int n = 020131452;
        int n = 20131452; 
        
        int sum = 0;
        for (int i = 2; i <= 10; i++){
            
            //System.out.println(n%10 + " * " + i);
            sum += n%10 * i;
            
            n = n/10;
        }
        
        
        
        for (int i=0;i<10;i++){
            int temp_sum = sum + i;
            if(temp_sum%11 == 0){
                
                System.out.println(i);
            }
        }
    }   
}
