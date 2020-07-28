# See explanation : https://leetcode.com/problems/super-egg-drop/solution/

int superEggDrop(int k, int n){
        int table[n+1][k+1];
        for(int i=1;i<=n;i++)
            table[i][1]=i;
        for(int i=1;i<=k;i++)
        {
            table[0][i]=0;
            table[1][i]=1;
        }
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                table[j][i]=INT_MAX;
                for(int x=1;x<=j;x++){
                    int res=max(table[x-1][i-1],table[j-x][i])+1;
                    table[j][i]=min(table[j][i],res);
                }
            }
        }
        return table[n][k];
    }

//Best solution:
class Solution {
public:
    int s(int k,int x,int n){
        int sum=0,r=1;
        for(int i=1;i<=k;++i){
            r*=x-i+1;
            r/=i;
            sum+=r;
            if(sum>=n)
                break;
        }
        return sum;
    }
    int superEggDrop(int K, int N) {
        int l=1,h=N;
        while(l<h){
            int m=(l+h)/2;
            if(s(K,m,N)<N)
                l=m+1;
            else
                h=m;
        }
        return l;
    }
};


//A good Solution
int superEggDrop(int K, int N) {
        int t[N+1][K+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++)
            { t[i][j]=t[i-1][j-1]+t[i-1][j]+1;
                if(t[i][j]>=N)
                return i;}
        }
        return -1;
    }
/*explanation:
First, this is not an easy problem to understand. Before moving on, ask yourself how would you calculate the number of moves needed given 100 floors and 2 eggs
A Natural Thinking Process: Assume we need x moves to find the egg breaking point in 100 floors with 2 eggs available. The floor you should start with given 2 eggs is the x-th floor. WHY? Becase if the first egg breaks on the x-th floor, you should try to drop the second egg from 1-th floor all the way to (x-1)-th floor to find the breaking point (note that in total you make x moves in worst case). On the other hand, if the first egg doesn't break at x-th floor, you should then try to drop it on (x+(x-1))-th floor. WHY? Because if the egg breaks on the (x+(x-1))-th floor, you would try to drop the second egg on (x+1)-th floor, and in total you will also make x moves in the worst case.

With the above concept, how can we determin 'x' given 100 floor and 2 eggs ??? --> we want to solve the following formula: x + (x-1) + (x-2) + ... + 2 + 1 >= 100 --> x = 14. (this basic formula works for 2 eggs only, but it provides a crucial DP thinking foundation.)
This gives us an idea: If arr is a M by K matrix, where M is the number of moves, K is the number of eggs, and arr[m][k] is the number of floors that we can make m moves with k eggs.

Then, arr[m][k] = 1 + arr[m-1][k-1] + arr[m-1][k] ---> where '1 + arr[m-1][k-1]' is the exact floor that you should try to drop the first egg. WHY ??? If you drop the first egg higher than this floor and it breaks, then you are not guaranteed to find the breaking point. Because you have "m-1" moves and "k-1" eggs left, and you are in a position (strictly) higher than arr[m-1][k-1] floor.

As for arr[m-1][k] , it represents the remaining floor we can check if the first egg dropping form the (1 + arr[m-1][k-1])-th floor is not broken. Therefore, given m moves and k eggs we can check 1 + arr[m-1][k-1] + arr[m-1][k] number of floors in total!

If you still don't get it. No worry. Please see the below comments in code:

def superEggDrop(self, K: int, N: int) -> int:
		# M x K --> Given M moves and K eggs, what is the maximum floor we can check ?
        M = 300 # big enough number
        dp = [[0 for j in range(K+1)] for i in range(M+1)]
        # Initialization 1 --> no move no floor --> dp[0][*] = 0
        # Initialization 2 --> no egg no floor --> dp[*][0] = 0
        # General case --> we want to find dp[m][k] --> we pick one egg and drop (1 move)
        #              --> now we have k or k-1 eggs, depending on whether the previous egg is broken
        #              --> so in either case, we can at least sum up 1 (first move) + dp[m-1][k] + dp[m-1][k-1] 
        for i in range(1, M+1):
            for j in range(1, K+1):
                dp[i][j] = 1 + dp[i-1][j] + dp[i-1][j-1]
                if dp[i][j] >= N:
                    return i
                    */


// gfg concept of above - https://www.geeksforgeeks.org/eggs-dropping-puzzle-set-2/?ref=rp
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum number 
// of trials needed in the worst case 
// with n eggs and k floors 
int eggDrop(int n, int k) 
{ 
	vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0)); 

	int x = 0; 

	// Fill all the entries in table using 
	// optimal substructure property 
	while (dp[x][n] < k) { 

		x++; 
		for (int i = 1; i <= n; i++) 
			dp[x][i] = dp[x - 1][i - 1] + dp[x - 1][i] + 1; 
	} 

	// Return the minimum number of moves 
	return x; 
} 

// Driver code 
int main() 
{ 
	int n = 2, k = 36; 

	cout << eggDrop(n, k); 

	return 0; 
} 
