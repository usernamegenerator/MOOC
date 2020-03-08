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
public class YIQtoRGB {
    public static void main(String[] args){
        int y = (int) (Math.random() * 255);
        int i = (int) (Math.random() * 255);
        int q = (int) (Math.random() * 255);
        
        int r = (int)(1*y + 0.956*i + 0.621*q);
        int g = (int)(1*y + (-0.272)*i + (-0.647)*q);
        int b = (int)(1*y + (-1.106)*i + 1.703*q);
        
        System.out.println("YIQ: ");
        System.out.println(y);
        System.out.println(i);
        System.out.println(q);
        
        System.out.println("RBG: ");
        System.out.println(r);
        System.out.println(g);
        System.out.println(b);
        
        
    }
}
