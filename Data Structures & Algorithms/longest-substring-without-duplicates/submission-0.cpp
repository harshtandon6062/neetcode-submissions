class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen_at;
        int l = 0, r = 0, n = s.size(), l_sub_str_len = 0;
        while(r < n){
            if(!seen_at.count(s[r])){
                seen_at[s[r]] = r;
            }
            else{
                for(int i = l; i < seen_at[s[r]]; i++)seen_at.erase(s[i]);
                l = seen_at[s[r]]+1;
                seen_at[s[r]] = r;
            }
            r++;
            l_sub_str_len = max(l_sub_str_len, r-l);
        }
        return l_sub_str_len;
    }
};
