/*
from random import choices
class Solution:

    def __init__(self, w: List[int]):
        self.l = [i for i in range(len(w))]
        self.w = w

    def pickIndex(self) -> int:
        return choices(population=self.l,weights=self.w,k=1)[0]


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex() */

class Solution {
public:
    vector<int> a;
    Solution(vector<int>& w) {
        a.clear();
        for(int i:w){
            if(a.empty())
                a.push_back(i);
            else
                a.push_back(i+a.back());
        }
    }
    
    int pickIndex() {
        int r=rand()%a.back();
        return upper_bound(a.begin(),a.end(),r)-a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
