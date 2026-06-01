class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node) {
        int cur = node;
        while (cur != parent[cur]) {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }
    void ds_union(int a, int b){
        if(rank[a] >= rank[b]){
            parent[b] = a;
            rank[a] += rank[b];
        }
        else {
            parent[a] = b;
            rank[b] += rank[a];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.push_back(0);
        rank.push_back(0);
        for(int i = 1; i <= n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(auto& edge: edges){
            int a = find(edge[0]), b = find(edge[1]);
            if(a==b) return edge;
            ds_union(a, b);
        }
        return {};

    }
};
