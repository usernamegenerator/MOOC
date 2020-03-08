/*
RGB to YIQ color converter. Write a program RGBtoYIQ.javathat takes an RGB color (three integers between 0 and 255) and 
transforms it to an YIQ color (three different integers between 0 and 255). 
Write a program YIQtoRGB.java that applies the inverse transformation.
 */
package ElementsOfProgramming;

/**
 *
 * @author ssdrive
 */
//https://en.wikipedia.org/wiki/YIQ
//wiki pedia has different definition of RGB and YIQ integers' range 
public class RGBtoYIQ {
    public static void main(String[] args){
        int r = (int) (Math.random() * 255);
        int g = (int) (Math.random() * 255);
        int b = (int) (Math.random() * 255);
        
        int y = (int)(0.299*r + 0.587*g + 0.114*b);
        int i = (int)(0.596*r + (-0.274)*g + (-0.322)*b);
        int q = (int)(0.211*r + (-0.523)*g+0.312*b);
        
        System.out.println("RBG: ");
        System.out.println(r);
        System.out.println(g);
        System.out.println(b);
        
        System.out.println("YIQ: ");
        System.out.println(y);
        System.out.println(i);
        System.out.println(q);
    }
}
