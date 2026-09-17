class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto lb = lower_bound(
            intervals.begin(), 
            intervals.end(), 
            newInterval[0], 
            [](const vector<int>& interval, int start){
                return interval[1] < start;
            }
        );

        auto ub = upper_bound(
            intervals.begin(), 
            intervals.end(), 
            newInterval[1],
            [](int end, const vector<int>& interval){
                return end < interval[0];
            }
        );
        if(lb == ub){
            intervals.insert(lb, newInterval);
            return intervals;
        }
        vector<int> merged_interval = {
            min((*lb)[0], newInterval[0]), 
            max((*(ub-1))[1], newInterval[1])
        };
        intervals.erase(lb, ub);
        intervals.insert(lb, merged_interval);
        return intervals;
    }
};
