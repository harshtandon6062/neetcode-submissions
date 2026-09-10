class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int m, n;
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(grid[i][j] != '1') return;
        grid[i][j] += 2;
        for(auto & d: dir){
            i+= d[0]; j+= d[1];
            if(i >=0 && i < m && j >= 0 && j < n)dfs(grid, i, j);
            i-= d[0]; j-= d[1];
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1') count++;
                dfs(grid, i, j);
            }
        }
        return count;
    }
};
