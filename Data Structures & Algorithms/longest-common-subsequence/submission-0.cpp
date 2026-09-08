class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp_prv(n+1, 0);
        for(int i = 1; i <= m; i++){
            vector<int> dp_cur(n+1, 0);
            vector<int> last_ind(26,-1);
            for(int j = 1; j <= text2.size(); j++){
                last_ind[text2[j-1]-'a'] = j-1;
                int skip = dp_prv[j]; 
                int take = 0;
                int last_index = last_ind[text1[i-1] - 'a'];
                if(last_index != -1) take = 1+dp_prv[last_index];
                dp_cur[j] = max(skip, take);
            }
            dp_prv = dp_cur;
        }
        return dp_prv[n];
    }
};
