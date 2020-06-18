/* Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
Example:
Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note:
If there are several possible values for h, the maximum one is taken as the h-index. */

// Sorted input
class Solution {
public:
    int f(vector<int> citations,int l,int h,int n){
        if(l>h)
            return 0;
        if(l==h){
            if(citations[l]>=n-l)
                return n-l;
            else
                return 0;
        }
        int m=(l+h)/2;
        if(citations[m]>=n-m&&(m==0||(m>0&&citations[m-1]<n-m)))
            return n-m;
        if(citations[m]<n-m)
            return f(citations,m+1,h,n);
        else
            return f(citations,l,m,n);
    }
    
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        return f(citations,0,n-1,n);
    }
};

// Unsorted input
class Solution {
public:
    int f(vector<int> citations,int l,int h,int n){
        if(l>h)
            return 0;
        if(l==h){
            if(citations[l]>=n-l)
                return n-l;
            else
                return 0;
        }
        int m=(l+h)/2;
        if(citations[m]>=n-m&&(m==0||(m>0&&citations[m-1]<n-m)))
            return n-m;
        if(citations[m]<n-m)
            return f(citations,m+1,h,n);
        else
            return f(citations,l,m,n);
    }
    
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        return f(citations,0,n-1,n);
    }
};
