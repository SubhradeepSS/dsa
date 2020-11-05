// Remove k digits to form smallest no
class Solution {
public:
    void f(string num,int k,string &ans){
        int l=num.length();
        if(k==0){
            ans.append(num);
            return;
        }
        if(k>=l)
            return;
        int min=0;
        for(int i=1;i<=k;i++){
            if(num[i]<num[min])
                min=i;
        }
        ans.push_back(num[min]);
        f(num.substr(min+1,l-min),k-min,ans);
    }
    string removeKdigits(string num, int k) {
        string ans="";
        f(num,k,ans);
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        ans.erase(0,i);
        if(ans=="")
            return "0";
        return ans;
    }
};
