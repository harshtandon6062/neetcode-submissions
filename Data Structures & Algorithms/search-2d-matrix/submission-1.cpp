class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1;
        int m;
        while(l<=r){
            m = (l+r)/2;
            if (target == matrix[m][0]) return true;
            else if (target > matrix[m][0] ) l = m+1;
            else r = m-1;
        }
        int i = min(l,r);
        if (i < 0 || i >= matrix.size()) return false;
        l = 0, r = matrix[0].size()-1;
        while(l<=r){
            m = (l+r)/2;
            if (target == matrix[i][m]) return true;
            else if (target > matrix[i][m]) l = m+1;
            else r = m-1;
        }
        return false;
        
    }
};
