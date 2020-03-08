/*
Minesweeper. Write a program Minesweeper.java that takes 3 command-line arguments m, n, and p 
and produces an m-by-n boolean array where each entry is occupied with probability p. 
In the minesweeper game, occupied cells represent bombs and empty cells represent safe cells. 
Print the array using an asterisk for bombs and a period for safe cells. 
Then, replace each safe square with the number of neighboring bombs (above, below, left, right, or diagonal) 
and print the solution.
* * . . .       * * 1 0 0
. . . . .       3 3 2 0 0
. * . . .       1 * 1 0 0

 */
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class Minesweeper {
    public static void main(String[] args){
        int m = 5;
        int n = 5;
        double p = 0.3;
        
        String[][] board = new String[m][n];
        //1. generate board
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                double random = Math.random();
                if(random <= 0.3){
                    board[i][j] = "*";
                }
                else{
                    board[i][j] = ".";
                }
            }
        }
        //2. print board with either * or .
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        
        //3.replace safe zone with numbers
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                //if it is a safe zone;
                if(board[i][j].equals(".")){
                    int CountOfMines = 0;
                    //go through the neibor zones
                    for(int ii=i-1;ii<=i+1;ii++){
                        if(ii<0 || ii >= m){
                            continue;
                        }
                        for(int jj=j-1;jj<=j+1;jj++){
                            if(jj<0 || jj>=n){
                                continue;
                            }
                                
                            //if neibor zone is mine, increment the count
                            if(board[ii][jj].equals("*")){
                                CountOfMines++;
                            }
                        }
                    }
                    
                    board[i][j] = Integer.toString(CountOfMines);
                }
            }
        }
        //print new board
        System.out.println();
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        
        
    }
}
