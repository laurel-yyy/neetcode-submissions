class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> cnt;
        for(char c : s1) {
            cnt[c]++;
        }
        int need = cnt.size();
        int have = 0;
        for(int i=0; i<s1.size(); ++i){
            cnt[s2[i]]--;
            if(cnt[s2[i]] == 0)have++;
        }
        if(have == need)return true;
        for(int i=s1.size(); i<s2.size(); ++i){
            cnt[s2[i]]--;
            if(cnt[s2[i]] == 0)have++;
            cnt[s2[i-s1.size()]]++;
            if(cnt[s2[i-s1.size()]] == 1)have--;
            if(have == need)return true;
        }
        return false;

    }
};
