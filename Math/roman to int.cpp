class Solution {
public:
    int f(char a){
        if(a=='I')
            return 1;
        if(a=='V')
            return 5;
        if(a=='X')
            return 10;
        if(a=='L')
            return 50;
        if(a=='C')
            return 100;
        if(a=='D')
            return 500;
        if(a=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int a=f(s[i]);
            if(i+1<s.length()){
                int b=f(s[i+1]);
                if(b>a){
                    ans+=b-a;
                    i++;
                }
                else
                    ans+=a;
            }
            else
                ans+=a;
        }
        return ans;
    }
};
