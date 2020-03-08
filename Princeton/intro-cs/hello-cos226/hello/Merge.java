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

public class Merge {

    //merge s[low,mid] and s[mid,high]
    private static void merge(Comparable[] s, Comparable[] aux, int low, int mid, int high) {
        int i = low, j = mid;

        for (int k = low; k < high; k++) {
            if (i == mid)
                aux[k] = s[j++]; //s[low,mid] run to the end, keeps copying [mid,high]
            else if (j == high)
                aux[k] = s[i++]; //s[mid,high] run to the end, keeps copying [low,mid]
            else if (s[j].compareTo(s[i]) < 0)
                aux[k] = s[j++];
            else
                aux[k] = s[i++];
        }

        for (int k = 0; k < high; k++) {
            s[k] = aux[k];
        }
    }

    public static void sort(Comparable[] s, Comparable[] aux, int low, int high) {

        if (high - low <= 1) return;

        int mid = low + (high - low) / 2;
        sort(s, aux, low, mid);
        sort(s, aux, mid, high);
        merge(s, aux, low, mid, high);
    }

    public static void sort(Comparable[] s) {
        int n = s.length;
        Comparable[] aux = new Comparable[n];
        sort(s, aux, 0, n);
    }


    public static void show(Comparable[] s) {
        int n = s.length;
        for (int i = 0; i < n; i++) {
            System.out.print(s[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        String[] s = { "and", "had", "him", "was", "but", "his", "the", "you" };
        Merge.sort(s);
        Merge.show(s);

    }
}
