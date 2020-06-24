# Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?=Catalan No
class Solution {
public:
    long long int ncr(int n,int r){
        long long int ans=1;
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    int numTrees(int n) {
        return ncr(2*n,n)/(n+1);
    }
};
