class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        vector<vector<int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                pair<int, int> pos = q.front(); q.pop();
                for(auto& dir: directions){
                    int x = pos.first + dir[0], y = pos.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            minute++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return (minute == 0)? minute : minute-1;
    }
};