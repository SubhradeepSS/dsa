/*Given a 32-bit signed integer, reverse digits of an integer.Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.*/
class Solution {
public:
    int reverse(int m) {
        long long int s=0,f=0;
        if(m<0)
        {
            if(m==INT_MIN)
                return 0;
            m*=-1;
            f=1;
        }
        while(m>0){
            if(s*10>INT_MAX)
                return 0;
            s=s*10+m%10;
            m/=10;
        }
        if(f==1)
            return -s;
        
        return s;
    }
};
