class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+2);
        dp[s.size()+1] = 0;
        dp[s.size()] = 1;
        for(int i=s.size()-1; i>=0; --i){
            if(s[i] == '0') dp[i] = 0;
            else if(s[i] == '1') dp[i] = dp[i+1]+ dp[i+2];
            else if(s[i] == '2' && i != s.size()-1 && s[i+1] < '7')dp[i] = dp[i+1]+ dp[i+2];
            else dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
