class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seq_beg;
        for(int num: nums){
            seq_beg[num] = num;
        }
        int max_len = 0;
        for(auto & p: seq_beg){
            if(p.first != p.second) continue;
            int beg = p.first;
            while(seq_beg.count(beg-1))beg--;
            for(int i = beg + 1; i <= p.second; i++) seq_beg[i] = beg;
            max_len = max(max_len, p.first - beg + 1);
        }
        return max_len;
    }
};

// {
//     0:0
//     3:0
//     2:0
//     5:5
//     4:4
//     6:6
//     1:0
// }