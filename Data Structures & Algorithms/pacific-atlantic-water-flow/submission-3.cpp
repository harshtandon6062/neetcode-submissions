class Solution {
public:
    int m, n;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool in_range(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& seen, int i, int j){
        if(seen[i][j])return;
        seen[i][j] = true;
        for(auto &d: dir){
            int i_nei = i+d[0], j_nei = j+d[1];
            if(in_range(i_nei,j_nei) && heights[i_nei][j_nei] >= heights[i][j])
                dfs(heights, seen, i_nei, j_nei);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        vector<vector<bool>> pacific_reachable(m, vector<bool>(n));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            dfs(heights, pacific_reachable, i, 0);
            dfs(heights, atlantic_reachable, i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(heights, pacific_reachable, 0, j);
            dfs(heights, atlantic_reachable, m-1, j);
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic_reachable[i][j] && pacific_reachable[i][j]) res.push_back({i,j});
            }
        }

        return res;
    }
};
