class Solution {
public:
    vector<vector<int>> ans;
    void findpath(vector<int>& nums, int i, vector<int>& path, int target){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(i == nums.size() || target < nums[i]) return; 
        findpath(nums, i+1, path, target);
        path.push_back(nums[i]);
        findpath(nums, i, path, target-nums[i]);
        path.pop_back(); 
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        findpath(nums,0, path, target);
        return ans;
    }
};
