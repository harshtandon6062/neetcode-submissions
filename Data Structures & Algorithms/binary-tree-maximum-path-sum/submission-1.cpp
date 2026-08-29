class Solution {
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }

private:
    int res = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left  = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        res = max(res, left + root->val + right);
        return max(left, right) + root->val;
    }
};