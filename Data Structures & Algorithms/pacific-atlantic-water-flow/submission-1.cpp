class Solution {
public:
    const char UNASSIGNED = ' ', PACIFIC = 'P', ATLANTIC = 'A', BOTH = 'B', NONE = 'N';
    const vector<pair<int,int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};

    char dfs(vector<vector<char>>& dp, vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        if (dp[i][j] != UNASSIGNED) return dp[i][j];
        visited[i][j] = true;
        unordered_set<char> s;
        for(auto& p: directions){
            int x = p.first, y = p.second;
            if(!visited[i+x][j+y] && heights[i+x][j+y] <= heights[i][j]){
                s.insert(dfs(dp, heights, visited, i+x, j+y));
            } 
        }
        if(s.count(BOTH) || (s.count(PACIFIC) && s.count(ATLANTIC))) return BOTH;
        if(s.count(ATLANTIC)) return ATLANTIC;
        if(s.count(PACIFIC)) return PACIFIC;
        return NONE;
    }   

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> heights_padded (m+2, vector<int>(n+2,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                heights_padded[i+1][j+1] = heights[i][j];
            }
        }
        vector<vector<char>>dp (m+2, vector<char>(n+2, UNASSIGNED));
        for(int k = 0; k < m+2; k++){
            dp[k][0] = PACIFIC;
            dp[k][n+1] = ATLANTIC; 
        }
        for(int k = 0; k < n+2; k++){
            dp[0][k] = PACIFIC;
            dp[m+1][k] = ATLANTIC; 
        }
        vector<vector<int>> res;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] != UNASSIGNED) continue;
                vector<vector<bool>>visited (m+2,vector<bool>(n+2,false));
                dp[i][j] = dfs(dp, heights_padded, visited, i, j);
                if(dp[i][j] == BOTH) res.push_back({i-1,j-1});
            }
        }
        return res;
    }
};
