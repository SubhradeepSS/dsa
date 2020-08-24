def stock(arr,n):
    i=0
    while i<n:
        while i<n-1 and arr[i+1]<=arr[i]:
            i+=1
        if i==n-1:
            break
        buy=i
        i+=1
        while i<n-1 and arr[i+1]>=arr[i]:
            i+=1
        sell=i
        print(buy,sell)
        
    
arr=[ 100, 180, 260, 310, 40, 535, 695 ]
stock(arr,len(arr))

# Buy sell at most 2 times
"""
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> p(n,0);
        int max_=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>max_)
                max_=prices[i];
            p[i]=max(p[i+1],max_-prices[i]);
        }
        int min_=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<min_)
                min_=prices[i];
            p[i]=max(p[i-1],p[i]+prices[i]-min_);
        }
        return p[n-1];
    }
};
"""
