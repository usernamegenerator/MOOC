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
public class Deal {
    public static void main(String[] args){
        //int players = (int)(Math.random()*4);
        int players = 4;
        int CARDS_PER_PLAYER = 5;
        
        String[] suits = {"Clubs","Diamonds","Hearts","Spades"};
        String[] ranks = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        
        int size = suits.length * ranks.length;
        
        String[] decks = new String[size];
        
        for(int i = 0; i < suits.length ; i++){
            for(int j = 0; j < ranks.length; j++){
                decks[i*ranks.length+j] = ranks[j] + " of " + suits[i];
            }
        }
        /*
        for(String deck : decks)
            System.out.println(deck);
        */
        for(int i = 0 ; i < size ; i++){
            int n = i+(int)(Math.random()*(size-i));
            String temp = decks[n];
            decks[n] = decks[i];
            decks[i] = temp;
        }
        
        for(int i = 1; i <= players * CARDS_PER_PLAYER; i++){
            System.out.println(decks[i]);
            if (i%CARDS_PER_PLAYER==0){
                System.out.println();
            }
        }
    }
}
