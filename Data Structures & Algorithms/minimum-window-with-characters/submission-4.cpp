class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ds;
        unordered_map<char, int> dt;
        for(char c : t){
            dt[c]++;
        }
        int l = 0;
        int has = 0;
        int need = dt.size();
        int minLen = INT_MAX;
        int startIdx = -1;
        for(int r=0; r<s.size(); ++r){
            ds[s[r]]++;
            if(dt.count(s[r]) && ds[s[r]] == dt[s[r]]){
                has++;
            }
            while(has == need){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startIdx = l;
                }
                if(dt.count(s[l]) && ds[s[l]] == dt[s[l]]) -- has;
                ds[s[l]]--;
                ++l;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};