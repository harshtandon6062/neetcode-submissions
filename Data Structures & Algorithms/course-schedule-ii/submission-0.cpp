class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>incoming_count(n, 0);
        for(auto& preq: prerequisites){
            adj[preq[1]].push_back(preq[0]);
            incoming_count[preq[0]]++;
        }
        queue<int>zero_incoming;
        for(int i = 0; i < n; i++){
            if(incoming_count[i] == 0) zero_incoming.push(i);
        }
        vector<int> res;
        while(!zero_incoming.empty()){
            int course = zero_incoming.front(); zero_incoming.pop();
            res.push_back(course);
            for(int nei: adj[course]){
                incoming_count[nei]--;
                if(incoming_count[nei] == 0) zero_incoming.push(nei);
            }
        }
        if(res.size() < n) return {};
        return res;
    }
};