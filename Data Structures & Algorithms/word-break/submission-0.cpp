struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        // Combine the hashes of first and second
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<pair<int,int>, pair_hash> found;
        unordered_set<pair<int,int>, pair_hash> temp;
        int n = s.size(), m = wordDict.size();
        for (int k = 0; k < m; k++) {
            if (s[0] == wordDict[k][0]) found.insert({k,0});
        }

        for (int i = 0; i < n; i++) {
            temp.clear();
            for (auto [x, y] : found) {
                if (wordDict[x][y] == s[i]) {
                    if (y == (int)wordDict[x].size() - 1) {
                        if (i == n-1) return true;
                        for (int k = 0; k < m; k++) {
                            if (s[i+1] == wordDict[k][0]) temp.insert({k,0});
                        }
                    } else {
                        temp.insert({x,y+1});
                    }
                }
            }
            swap(found, temp);
        }
    return false;

    }
};