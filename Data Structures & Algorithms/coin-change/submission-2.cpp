class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, INT_MAX-1));
        for(int i=0; i<coins.size(); ++i){
            dp[i+1][0] = 0;
        }
        for(int i=0; i<coins.size(); ++i){
            for (int j = 1; j <= amount; ++j) {
                dp[i+1][j] = dp[i][j];           
                if (j >= coins[i]) {
                    dp[i+1][j] = min(dp[i+1][j], dp[i+1][j - coins[i]] + 1); 
                }
            }
        }
        if(dp[coins.size()][amount] == INT_MAX-1)return -1;
        return dp[coins.size()][amount];
    }
};
