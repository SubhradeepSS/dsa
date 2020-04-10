// Completely O(1) but using inbuilt stack and vector
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    vector<int> min;
    MinStack() {
        while(!st.empty())
            st.pop();
        min.clear();
    }
    
    void push(int x) {
        if(st.empty())
            min.push_back(x);
        else if(x<=min[min.size()-1])
            min.push_back(x);
        st.push(x);
    }
    
    void pop() {
      if(st.top()==min[min.size()-1])
          min.pop_back();
      st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min[min.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
