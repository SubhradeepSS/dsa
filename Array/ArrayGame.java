// https://www.codechef.com/SCC82021/problems/SSEC0131

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans = 0;
        HashMap<Integer, Integer> hs = new HashMap<>();
        for (int i = 0; i < m; i++) {
            if (hs.get(a[i]) == null) {
                hs.put(a[i], 1);
                ans++;
            } else {
                hs.put(a[i], hs.get(a[i]) + 1);
            }
        }
        int util = ans;
        for (int i = m; i < n; i++) {
            if (hs.get(a[i - m]) == 1) {
                hs.remove(a[i - m]);
                util--;
            } else {
                hs.put(a[i - m], hs.get(a[i - m]) - 1);
            }
            if (hs.get(a[i]) == null) {
                hs.put(a[i], 1);
                util++;
            } else {
                hs.put(a[i], hs.get(a[i]) + 1);
            }
            ans = Math.max(util, ans);
        }
        System.out.println(ans);
    }
}
