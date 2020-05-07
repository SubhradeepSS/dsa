int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        int i=0,tp,max=0,area;
        while(i<n){
            if(s.empty()||heights[i]>=heights[s.top()])
                s.push(i++);
            else{
                tp=s.top();
                s.pop();
                area=heights[tp]*(s.empty()?i:i-s.top()-1);
                if(area>max)
                    max=area;
            }
        }
        while(!s.empty()){
            tp=s.top();
            s.pop();
            area=heights[tp]*(s.empty()?i:i-s.top()-1);
            if(area>max)
                max=area;
        }
        return max;
    }
