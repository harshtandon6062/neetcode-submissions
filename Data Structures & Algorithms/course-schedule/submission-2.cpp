class Solution {
public:
    int n;
    bool has_cycle(vector<vector<int>>& adj, unordered_set<int>& visited,  unordered_set<int>& path_visited, int node){
        visited.insert(node);
        path_visited.insert(node);
        for(int nei: adj[node]){
            if(path_visited.count(nei)) return true;
            else if (!visited.count(nei)){
                if(has_cycle(adj, visited, path_visited, nei)) return true;
            }
        }
        path_visited.erase(node);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& preq: prerequisites){
            adj[preq[1]].push_back(preq[0]);
        }
        unordered_set<int> visited;
        unordered_set<int> path_visited;
        for(int node = 0; node < n; node++){
            if(!visited.count(node)){
                if(has_cycle(adj, visited, path_visited, node)) return false;
            }
        }
        return true;
    }
};