class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n);
        dp[0].push_back(0);
        int max_size = 1;
        string lps = s.substr(0,1);
        for(int i = 1; i < n; i++){
            dp[i].push_back(i);
            if (s[i] == s[i-1]){
                dp[i].push_back(i-1);
                if (2 > max_size){
                    max_size = 2;
                    lps = s.substr(i-1,2);
                }
            } 
            for(int start: dp[i-1]){
                if (start > 0 && s[start-1] == s[i]){
                    dp[i].push_back(start-1);
                    int len = i - start + 2;
                    if (len > max_size){
                        max_size = len;
                        lps = s.substr(start-1, len);
                    }
                }
            }
        }
        return lps;
    }
};
