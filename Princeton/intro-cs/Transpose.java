/******************************************************************************
 *  Compilation:  javac Transpose.java
 *  Execution:    java Transpose n
 *  
 *  Transpose an n-by-n matrix in-place, without creating a second
 *  2D array.
 *
 *  Submitted by Christian Rubio.
 *
 ******************************************************************************/
package ElementsOfProgramming;

/**
            {1,2,3},
            {4,5,6},
            {7,8,9}
            * 
            * to
            * 
            {1,4,7},
            {2,5,8},
            {3,6,9}
 */
public class Transpose {
    public static void main(String[] args){
        int [][] original= {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        
        for(int i = 0; i < 3 ; i++){
            for(int j = i ; j < 3; j++){
                if(i!=j){
                    int temp = original[i][j];
                    original[i][j] = original[j][i];
                    original[j][i] = temp;
                }
            }
        }
        
        for(int i = 0; i < 3 ; i++){
            for(int j=0 ; j < 3; j++){
                System.out.print(original[i][j] + " ");
            }
            System.out.println();
        }
    }
}
