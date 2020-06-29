// https://youtu.be/GSBLe8cKu0s
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        
        vector<vector<int>> points;
        for(auto b:buildings){
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        }
        
        int pre_max=0,curr_max;
        ms.insert(0);
        sort(points.begin(),points.end());
        
        vector<vector<int>> ans;
        
        for(auto p:points){
            if(p[1]<0){
                ms.insert(-p[1]);
            }
            else{
                ms.erase(ms.find(p[1]));
            }
            curr_max=*ms.rbegin();
            if(curr_max!=pre_max){
                ans.push_back({p[0],curr_max});
                pre_max=curr_max;
            }
        }
        
        return ans;
    }
};
