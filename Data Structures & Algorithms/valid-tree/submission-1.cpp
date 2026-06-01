class Solution {
public:
    bool has_cycle(int n, vector<vector<int>>& adj, vector<bool>& visited, int parent, int node){
        visited[node] = true;
        for(int nei: adj[node]){
            if(!visited[nei]){
                if(has_cycle(n, adj, visited, node, nei)) return true;
            }
            else if (nei != parent) return true;
        }
        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        if(has_cycle(n, adj, visited, -1, 0)) return false;
        for(int node = 0; node < n; node++){
            if(!visited[node]) return false;
        }
        return true;

    }
};
