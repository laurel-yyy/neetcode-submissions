class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for(int i=0; i<height.size(); ++i){
            if(stk.empty() || height[i] <= height[stk.top()]) {
                stk.push(i);
            } else {
                int bottom = height[stk.top()];
                stk.pop();
                while(!stk.empty() && height[stk.top()] < height[i]){
                    ans += (min(height[stk.top()], height[i]) -bottom)*(i-stk.top()-1);
                    bottom = height[stk.top()];
                    stk.pop();
                }
                if(!stk.empty())ans += (min(height[stk.top()], height[i]) -bottom)*(i-stk.top()-1);
                stk.push(i);
            }
        }
        return ans;
    }
};
