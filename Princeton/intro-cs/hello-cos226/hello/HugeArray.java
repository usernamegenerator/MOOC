/*
Describe and explain what happens when you try to compile a program HugeArray.java with the following statement:

 */
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class HugeArray {
    public static void main(String[] args){
        int n = 1000;
        int[] a = new int[n*n*n*n];
    }
}
/*
Exception in thread "main" java.lang.NegativeArraySizeException
	at ElementsOfProgramming.HugeArray.main(HugeArray.java:15)
D:\github-repo\intro-cs\intro-cs\nbproject\build-impl.xml:1051: The following error occurred while executing this line:
D:\github-repo\intro-cs\intro-cs\nbproject\build-impl.xml:805: Java returned: 1
BUILD FAILED (total time: 0 seconds)
*/