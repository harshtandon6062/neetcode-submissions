class Solution {
public:
    //dfs(board, int i, res, invalid_col, invalid_p_diag, invalid_n_diag)
    // if ( i >= n) add board to res and return
    // for(j in range 0 to n-1)
        // find col, p_diag, n_diag(i-j) of cell(i,j)
        // if(all 3 are valid)
            // add all three to invalid sets
            // add queen at pos
            // call dfs(i+1, res, 3 invalid sets)
            // remove all three
            // remove queen from pos
    void dfs(vector<vector<string>>& res, vector<string>& board, unordered_set<int>& inv_col, unordered_set<int>& inv_p_diag, unordered_set<int>& inv_n_diag, int i){
        if(i >= board.size()){
            res.push_back(board);
            return;
        }
        for(int j = 0; j < board.size(); j++){
            int col = j, p_diag = i-j, n_diag = i+j;
            if(!inv_col.count(col) && !inv_p_diag.count(p_diag) && !inv_n_diag.count(n_diag)){
                inv_col.insert(col);
                inv_p_diag.insert(p_diag);
                inv_n_diag.insert(n_diag);
                board[i][j] = 'Q';
                dfs(res, board, inv_col, inv_p_diag, inv_n_diag, i+1);
                inv_col.erase(col);
                inv_p_diag.erase(p_diag);
                inv_n_diag.erase(n_diag);
                board[i][j] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> inv_col, inv_p_diag, inv_n_diag;
        dfs(res, board, inv_col, inv_p_diag, inv_n_diag, 0);
        return res;
    }
};
