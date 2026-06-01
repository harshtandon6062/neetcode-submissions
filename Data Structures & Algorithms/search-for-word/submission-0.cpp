struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // simple combination
    }
};

class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, unordered_set<pair<int,int>, pair_hash>& s, int i, int j, int k){
        if (k >= word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        s.insert({i,j});
        bool res = false;
        if(i > 0 && !s.count({i-1,j}) && board[i-1][j] == word[k] && solve(board, word, s, i-1, j, k+1)) res = true;
        if(j > 0 && !s.count({i, j-1}) && board[i][j-1] == word[k] && solve(board, word, s, i, j-1, k+1))res = true;
        if(i < m-1 && !s.count({i+1,j}) && board[i+1][j] == word[k] && solve(board, word, s, i+1, j, k+1)) res = true; 
        if(j < n-1 && !s.count({i,j+1}) && board[i][j+1] == word[k] && solve(board, word, s, i, j+1, k+1)) res = true;
        s.erase({i,j});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                unordered_set<pair<int,int>, pair_hash> s;
                if(board[i][j] == word[0]){
                    if (solve(board, word, s, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};
