struct element{
    int num;
    int freq;
};
struct cmp_ele{
    bool operator()(const element& a, const element& b){
        return a.freq > b.freq;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num: nums){
            freq[num]++;
        }
        priority_queue<element, vector<element>, cmp_ele> pq;
        int count = 0;
        auto it = freq.begin();
        for (; it != freq.end(); ++it){
            if (count++ == k) break;
            pq.push({it->first, it->second});
        }
        for (; it != freq.end(); ++it){
            if (it->second > pq.top().freq){
                pq.pop();
                pq.push({it->first,it->second});
            }
        }

        vector<int>res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().num);
            pq.pop();
        }
        return res;
        
    }
};
