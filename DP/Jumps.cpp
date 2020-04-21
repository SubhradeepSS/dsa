#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[],int n){
    int jumps[n];
    if(arr[0]==0)
        return INT_MAX;
    jumps[0]=0;
    for(int i=1;i<n;i++){
        jumps[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i&&jumps[j]!=INT_MAX){
                jumps[i]=min(arr[i],1+jumps[j]);
                break;}
        }
    }
    return jumps[n-1];
}
int main() 
{ 
    int arr[] = { 1, 3, 6, 1, 0, 9 }; 
    int size = sizeof(arr) / sizeof(int); 
    cout << "Minimum number of jumps to reach end is " << minJumps(arr, size); 
    return 0; 
} 

//O(n) solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int first_good=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=first_good)
                first_good=i;
        }
        return (first_good==0);
    }
};
