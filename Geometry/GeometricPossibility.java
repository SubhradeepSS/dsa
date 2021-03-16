// LINK: https://www.codechef.com/SSC72021/problems/GEOPOS

// You are given length of n sides, you need to answer whether it is possible to make n sided convex polygon with it.
// Input:
//     First line contains T ,no .of testcases.
//     For each test case , first line consist of single integer N ,second line consist of
//     N(A1,A2,A3,A4,A5,A6…..AN ) spaced integers, size of each side.

// Output: For each test case print "Yes" if it is possible to make polygon or else "No" if it is not possible.

// Sample Input:
// 2
// 3
// 4 3 2 
// 4
// 1 2 1 4 

// Sample Output:
// Yes
// No

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while (t-- > 0) {
            int n;
            n = sc.nextInt();
            int sum = 0, maxS = 0;
            while (n-- > 0) {
                int x = sc.nextInt();
                sum += x;
                maxS = (maxS > x ? maxS : x);
            }
            if (sum - maxS > maxS) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
