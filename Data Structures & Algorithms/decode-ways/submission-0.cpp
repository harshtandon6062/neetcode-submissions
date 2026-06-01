class Solution {
public:
    int numDecodings(string s){
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for(int i = 2; i <= n ; i++){
            dp[i] += s[i-1] != '0' ? dp[i-1] : 0;
            int val = stoi(s.substr(i-2,2));
            if (val >=10 && val <= 26) dp[i] += dp[i-2];

        }
        return dp[n];
    }
};