class Solution {
public:
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>& visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = true;
        if(i > 0 && grid[i-1][j] == '1' && !visited[i-1][j])dfs(grid, visited, i-1, j);
        if(j > 0 && grid[i][j-1] == '1' && !visited[i][j-1])dfs(grid, visited, i, j-1);
        if(i < m-1 && grid[i+1][j] == '1' && !visited[i+1][j])dfs(grid, visited, i+1, j);
        if(j < n-1 && grid[i][j+1] == '1' && !visited[i][j+1])dfs(grid, visited, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
