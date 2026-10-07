class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int i = 0, j = 0;
        int l = 0, r = matrix[0].size(), t = 0, b = matrix.size();
        vector<int> res;
        while(i > t || i < b-1 || j > l || j < r-1){
            for(int k = 0; k < dir.size(); k++){
                vector<int> d = dir[k];
                while(i+d[0] >= t && i + d[0] < b && j + d[1] >= l && j + d[1] < r){
                    res.push_back(matrix[i][j]);
                    i+= d[0]; j += d[1];
                }   
                if(k == 0) t++;
                else if(k == 1) r--;
                else if(k == 2) b--;
                else if(k ==3)l++;
            }
        }
        res.push_back(matrix[i][j]);
        return res;
    }
};
