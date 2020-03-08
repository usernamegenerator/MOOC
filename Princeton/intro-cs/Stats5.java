/******************************************************************************
 *  Compilation:  javac Stats5.java
 *  Execution:    java Stats5
 *  
 *  Generate and print 5 random values between 0.0 and 1.0, and print
 *  their average value, min value, and max value.
 *
 *  % java Stats5
 *
 *  0.7203537279117841
 *  0.09574435157738448
 *  0.8979741693231866
 *  0.11949032184355113
 *  0.23425519545397544
 *  Average = 0.4135635532219763
 *  Min     = 0.09574435157738448
 *  Max     = 0.8979741693231866
 *
 *  % java Stats5
 *  0.25523821773554134
 *  0.6577131932424987
 *  0.14170223533941984
 *  0.2653444869526621
 *  0.895374957216799
 *  Average = 0.44307461809738424
 *  Min     = 0.14170223533941984
 *  Max     = 0.895374957216799
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class Stats5 {
    public static void main(String[] args){
        double one = Math.random();
        double two = Math.random();
        double three = Math.random();
        double four = Math.random();
        double five = Math.random();

        System.out.println("five numbers");
        System.out.println(one);
        System.out.println(two);
        System.out.println(three);
        System.out.println(four);
        System.out.println(five);
    
        double ave = (one + two + three + four + five) / 5;
        double min = Math.min(Math.min(Math.min(Math.min(one,two),three),four),five);
        double max = Math.max(Math.max(Math.max(Math.max(one,two),three),four),five);
        System.out.println("ave : " + ave);
        System.out.println("min : " + min);
        System.out.println("max : " + max);
        
    }      
}
