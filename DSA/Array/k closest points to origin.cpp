bool f(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
        return p1.first<p2.first;
    }
class Solution {
public:
    int dist(int x1,int y1){
        return x1*x1+y1*y1;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> p(n);
        for(int i=0;i<n;i++){
            p[i].first=dist(points[i][0],points[i][1]);
            p[i].second.first=points[i][0];
            p[i].second.second=points[i][1];
        }
        sort(p.begin(),p.end(),f);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<K;i++)
            ans.push_back({p[i].second.first,p[i].second.second});
        return ans;
    }
};

// Python solution
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        points.sort(key=lambda p:p[0]**2+p[1]**2)
        return points[:K]
        
