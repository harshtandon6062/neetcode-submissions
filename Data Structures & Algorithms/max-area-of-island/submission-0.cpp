class Solution {
public:

    int area(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        int m = grid.size(), n = grid[0].size();
        int res = 1;
        if(i + 1 < m && grid[i+1][j] && !visited[i+1][j]) res += area(grid, visited, i+1, j);
        if(i - 1 >= 0 && grid[i-1][j] && !visited[i-1][j]) res += area(grid, visited, i-1, j);
        if(j + 1 < n && grid[i][j+1] && !visited[i][j+1]) res += area(grid, visited, i, j+1);
        if(j - 1 >= 0 && grid[i][j-1] && !visited[i][j-1]) res += area(grid, visited, i, j-1);
        return res;

        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !visited[i][j]){
                    max_area = max(max_area, area(grid, visited, i, j));
                }
            }
        }
        return max_area;

    }
};
