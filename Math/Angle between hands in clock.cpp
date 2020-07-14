class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min,hr;
        min = double(6*minutes);
        hr = double((hour%12)*30+double(minutes)*double(0.5));
        
        double ans=abs(hr-min);
        
        return ans<360-ans?ans:360-ans;
    }
};
