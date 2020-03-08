/* *****************************************************************************
 *  Name:    Alan Turing
 *  NetID:   aturing
 *  Precept: P00
 *
 *  Partner Name:    Ada Lovelace
 *  Partner NetID:   alovelace
 *  Partner Precept: P00
 *
 *  Description:  Prints 'Hello, World' to the terminal window.
 *                By tradition, this is everyone's first program.
 *                Prof. Brian Kernighan initiated this tradition in 1974.
 *
 **************************************************************************** */

public class Rational {

    private final int numerator;
    private final int denominator;

    public Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw new RuntimeException("Denomiator is zero");
        }
        int g = gcd(numerator, denominator);
        this.numerator = numerator / g;
        this.denominator = denominator / g;
    }

    public String toString() {
        return numerator + " / " + denominator;
    }

    private static int gcd(int m, int n) {
        if (n == 0) return m;
        return gcd(n, m % n);
    }

    public Rational plus(Rational b) {
        Rational a = this;
        if (a.denominator == b.denominator) {
            return new Rational(a.numerator + b.numerator, denominator);
        }
        else {
            return new Rational(a.numerator * b.denominator + a.denominator * b.numerator,
                                a.denominator * b.denominator);
        }
    }

    public Rational minus(Rational b) {
        Rational a = this;
        return new Rational(a.numerator * b.denominator - a.denominator * b.numerator,
                            a.denominator * b.denominator);
    }

    public static void main(String[] args) {
        Rational a = new Rational(3, 4);
        Rational b = new Rational(1, 4);
        System.out.println(a.plus(b));
        System.out.println(a.minus(b));
    }
}
