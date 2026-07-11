class Solution {
public:
    void normalize(string &s){
        int ind = 0;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                s[ind++] = tolower(s[i]);
            }
        }
        s.resize(ind);
    }
    bool isPalindrome(string s) {
        normalize(s);
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return s_rev == s;
    }
};
