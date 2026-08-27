class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)return "";
        if(s.size() == 1)return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string ans = "";
        for(int i=s.size()-1; i>=0; --i){
            for(int j=i; j<s.size(); ++j){
                if(i == j) dp[i][j] = true;
                else if(j - i == 1)dp[i][j] = (s[i]==s[j]);
                else {
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }
                if(dp[i][j] && j-i+1> ans.size())ans = s.substr(i, j-i+1);
            }
        }
        return ans;
    }
};
