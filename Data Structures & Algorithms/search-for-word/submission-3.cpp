class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        bool res = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    res |= dfs(board, word, i, j, 1);
                }
            }
        }
        
        return res;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(k == word.size()) return true;
        char c = word[k];
        bool res = false;
        board[i][j] = '#';
        if(i > 0 && board[i-1][j] == c) res |= dfs(board, word, i-1, j, k+1);
        if(i < board.size()-1 && board[i+1][j] == c ) res |= dfs(board, word, i+1, j, k+1);
        if(j > 0 && board[i][j-1] == c) res |= dfs(board, word, i, j-1, k+1);
        if(j < board[0].size()-1 && board[i][j+1] == c) res |= dfs(board, word, i, j+1, k+1); 
        board[i][j] = word[k-1];
        return res;
    }
};
