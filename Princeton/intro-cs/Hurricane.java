/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ElementsOfProgramming;

/**
 *
 * @author yuhan
 */
public class Hurricane {
    public static void main(String[] args){
        int n = (int)(Math.random()*200);
        System.out.println(n);
        if(n<74){
            System.out.println("not hurricane");
        }
        else if(n<=95){
            System.out.println("hurricane 1");
        }
        else if(n<=110){
            System.out.println("hurricane 2");
        }
        else if(n<=130){
            System.out.println("hurricane 3");
        }
        else if(n<=155){
            System.out.println("hurricane 4");
        }
        else{
            System.out.println("hurricane 5");
        }
            
    }
}
