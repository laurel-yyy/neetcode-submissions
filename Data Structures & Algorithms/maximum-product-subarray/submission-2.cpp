class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        for(int i=1; i<nums.size(); ++i){
            int temp_max = curr_max;
            int temp_min = curr_min;
            curr_max = max({nums[i], temp_max*nums[i], temp_min*nums[i]});
            curr_min = min({nums[i], temp_max*nums[i], temp_min*nums[i]});
            max_prod = max(max_prod, curr_max);
        }
        return max_prod;
    }
};
