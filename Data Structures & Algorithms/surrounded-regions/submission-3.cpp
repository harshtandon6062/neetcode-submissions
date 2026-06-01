class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void mark_safe(vector<vector<char>>& board, vector<vector<bool>>& safe, int i, int j){
        safe[i][j] = true;
        for(auto& dir: directions){
            int x = i + dir[0], y = j + dir[1];
            if( x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !safe[x][y]){
                mark_safe(board, safe, x, y);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        m = board.size(); n = board[0].size();
        vector<vector<bool>> safe (m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !safe[i][0]) mark_safe(board, safe, i, 0);
            if(board[i][n-1] == 'O' && !safe[i][n-1]) mark_safe(board, safe, i, n-1);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !safe[0][j]) mark_safe(board, safe, 0, j);
            if(board[m-1][j]== 'O'&& !safe[m-1][j]) mark_safe(board, safe, m-1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!safe[i][j]) board[i][j] = 'X';
            }
        }
    }
};
