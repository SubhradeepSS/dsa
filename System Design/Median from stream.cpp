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
