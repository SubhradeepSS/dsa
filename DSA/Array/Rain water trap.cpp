class Solution {
public:
    int trap(vector<int>& height) {
        int la=0,ra=0,l=0,r=height.size()-1,ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>la){
                    la=height[l];
                }
                else{
                    ans+=la-height[l];
                }
                l++;
            }
            else{
                if(height[r]>ra)
                    ra=height[r];
                else
                    ans+=ra-height[r];
                r--;
            }
        }
        return ans;
    }
};
