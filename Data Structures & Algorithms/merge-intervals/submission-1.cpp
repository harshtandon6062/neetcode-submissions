class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int i = 0; 
        while(i < intervals.size()){
            vector<int> cur = intervals[i];
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] <= cur[1]){
                cur[1] = max(cur[1], intervals[j][1]);
                j++;
            } 
            merged.push_back(cur);
            i = j;
        }
        return merged;
    }
};
