class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int c=a&b;
            a=a^b;
            b=(unsigned)c<<1; //(unsigned) for negative nos
        }
        return a;
    }
};
