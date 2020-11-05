class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> count(10,0);
        for(int i:A)
            count[i]++;
        
        for(int i=2359;i>=0;i--){
            if((i%100)>=60)
                continue;
            vector<int> util(count.begin(),count.end());
            string curr=to_string(i);
            int x=4-curr.length();
            while(x--)
                curr='0'+curr;
            int j;
            for(j=0;j<4;j++){
                if(util[curr[j]-'0']>0)
                    util[curr[j]-'0']--;
                else
                    break;
            }
            if(j==4){
                curr=curr.substr(0,2)+":"+curr.substr(2,2);
                return curr;
            }
        }
        
        return "";
    }
};
