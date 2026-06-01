class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int n, int node){
        visited[node] = true;
        for(int nei: adj[node]){
            if(!visited[nei]) dfs(adj, visited, n, nei);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int comp_count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                comp_count++;
                dfs(adj, visited, n, i);
            }
        }
        return comp_count;

    }
};
