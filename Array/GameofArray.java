// https://www.codechef.com/SCC82021/problems/GARRAY

/* package codechef; // don't place package name! */
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        while (t-- > 0) {
            HashSet<Integer> hs = new HashSet<>();
            int n;
            n = sc.nextInt();
            while (n-- > 0) {
                hs.add(sc.nextInt());
            }
            String ans = (hs.size() % 2 == 0 ? "Aman" : "Raju");
            System.out.println(ans);
        }
    }
}
