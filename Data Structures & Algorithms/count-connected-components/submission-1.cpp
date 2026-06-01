class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node){
        int temp = node;
        while(parent[node] != node){
            node = parent[node];
        }
        parent[temp] = node;
        return node;
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
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        int num_components = n;
        for(auto& edge: edges){
            int a = find(edge[0]), b = find(edge[1]);
            if(a!=b){
                ds_union(a, b);
                num_components--;
            }
        }
        return num_components;

    }
};
