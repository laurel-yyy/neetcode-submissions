class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0];
        for(int i=1; i<nums.size(); ++i){
            step -= 1;
            if(step < 0) return false;
            step = max(step, nums[i]);
        }
        return true;
    }
};
