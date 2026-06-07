class Solution {
public:
    void dfs(unordered_map<char, string>& mp, vector<string>& res, string& comb, string digits, int i){
        if(i >= digits.size()){
            res.push_back(comb);
            return;
        }
        for(char c: mp[digits[i]]){
            comb.push_back(c);
            dfs(mp, res, comb, digits, i+1);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        string comb;
        int n = digits.size();
        dfs(mp, res, comb, digits, 0);
        return res;
    }
};
