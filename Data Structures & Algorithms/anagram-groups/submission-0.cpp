class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> map;
        int i = 0;
        for(string str: strs){
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            if (!map.count(sorted)){
                map[sorted] = i++;
                res.push_back({});
            }
            res[map[sorted]].push_back(str);
        }
        return res;
    }
};
