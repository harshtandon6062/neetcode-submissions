class Solution {
public:
    int characterReplacement(string s, int k) {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int max_len = 0;
        for(char c: alphabet){
            int l = 0, r = 0, replaced_count = 0;
            while(r < s.size()){
                if(s[r] == c) r++;
                else if(replaced_count < k){
                    r++;
                    replaced_count++;
                }
                else{
                    if(s[l] != c )replaced_count--;
                    if(l == r)r++;
                    l++;
                }
                max_len = max(max_len, r-l);
            }
            
        }
        return max_len;
    }
};

