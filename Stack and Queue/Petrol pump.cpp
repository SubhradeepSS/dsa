#include <bits/stdc++.h> 
using namespace std; 
struct petrolPump{
    int petrol;
    int dist;
};
int printTour(petrolPump arr[],int n){
    int start=0,end=1;
    int curr_petrol=arr[start].petrol-arr[start].dist;
    while(curr_petrol<0||start!=end){
        while(curr_petrol<0&&start!=end){
            curr_petrol-=arr[start].petrol-arr[start].dist;
            start=(start+1)%n;
            if(start==0)
                return -1;
        }
        curr_petrol+=arr[end].petrol-arr[end].dist;
        end=(end+1)%n;
    }
    return start;
}

int main()  
{  
    petrolPump arr[] = {{6, 4}, {3, 2}, {7, 3}};  
  
    int n = sizeof(arr)/sizeof(arr[0]);  
    int start = printTour(arr, n);  
  
    (start == -1)? cout<<"No solution": cout<<"Start = "<<start;  
  
    return 0;  
} 


// leetcode problem solution along with edge-case checking
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if(n==1)
            return (gas[0] >= cost[0] ? 0 : -1);
        int start=0,end=1,curr=gas[0]-cost[0];
        while(start!=end || curr<0){
            while(start!=end && curr<0){
                curr -= gas[start] - cost[start];
                start = (start+1)%n;
                if(start == 0)
                    return -1;
            }
            curr += gas[end] - cost[end];
            end = (end+1)%n;
        }
        return start;
    }
};
