class MedianFinder {
public:
    vector<int> v;
    /** initialize your data structure here. */
    MedianFinder() {
        v.clear();
    }
    
    void addNum(int num) {
        if(v.empty())
            v.push_back(num);
        else{
            v.insert(lower_bound(v.begin(),v.end(),num),num); //Using insertion sort and binary search concept
        }
    }
    
    double findMedian() {
        int n=v.size();
        if(n==0)
            return double(0);
        
        //sort(v.begin(),v.end());
        if(n%2!=0)
            return double(v[n/2]);
        
        return double((double(v[n/2])+double(v[n/2-1]))*0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// GFG solution
#include <queue>
#include <vector>
using namespace std;

int main() {
	//code
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    
    int med=a[0];
    max.push(med);
    
    cout<<med<<endl;
    for(int i=1;i<n;i++){
        int x=a[i];
        if(max.size()>min.size()){
            if(x<med){
                int t=max.top();
                max.pop();
                min.push(t);
                max.push(x);
            }
            else
                min.push(x);
            med=(min.top()+max.top())/2;
        }
        else if(max.size()<min.size()){
            if(x>med){
                max.push(min.top());
                min.pop();
                min.push(x);
            }
            else
              max.push(x);
          med=(max.top()+min.top())/2;
        }
        else{
            if(x<med){
                max.push(x);
                med=max.top();}
            else{
                min.push(x);
                med=min.top();
            }
        }
        cout<<med<<endl;
    }
	return 0;
}