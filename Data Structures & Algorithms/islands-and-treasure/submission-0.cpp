class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int i, int j, int dist){
        grid[i][j] = dist;
        for(auto& dir: directions){
            int x = i + dir[0], y = j + dir[1];
            if( x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > dist+1){
                dfs(grid, x, y, dist+1);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) dfs(grid, i, j, 0);
            }
        }
    }

};
