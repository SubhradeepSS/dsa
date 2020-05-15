class Solution {
public:
    int kadane(vector<int> a){
        int ans=0;
        int curr=0;
        for(int i=0;i<a.size();i++){
            curr+=a[i];
            if(curr<0)
                curr=0;
            ans=max(ans,curr);
        }
        return ans;
    }
    bool f(vector<int> A){
        for(int i=0;i<A.size();i++){
            if(A[i]>=0)
                return false;
        }
        return true;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        if(f(A))
            return *max_element(A.begin(),A.end());
        int ans1=kadane(A);
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            A[i]*=-1;
        }
        sum+=kadane(A);
        return max(sum,ans1);
    }
};
