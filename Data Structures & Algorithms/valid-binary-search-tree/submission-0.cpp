/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int lower_limit = INT_MIN;
        int upper_limit = INT_MAX;

        return validateBST(root, lower_limit, upper_limit);
    }
    bool validateBST(TreeNode* root, int lower_limit, int upper_limit){
        if(!root) return true;
        return (root->val > lower_limit && root->val < upper_limit 
        && validateBST(root->left, lower_limit, root->val) 
        && validateBST(root->right, root->val, upper_limit));
    }

};
