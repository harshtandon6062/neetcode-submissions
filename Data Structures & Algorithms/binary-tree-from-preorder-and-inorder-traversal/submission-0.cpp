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
    unordered_map<int, int> inorder_ind;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)inorder_ind[inorder[i]] = i;
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l, int in_r){
        if(pre_l > pre_r) return nullptr;
        int root_val = preorder[pre_l];
        TreeNode* root = new TreeNode(root_val);
        int root_ind = inorder_ind[root_val];
        int l_size = root_ind - in_l;
        root->left = helper(preorder, pre_l+1, pre_l+l_size, inorder, in_l, root_ind-1);
        root->right = helper(preorder, pre_l+l_size+1, pre_r, inorder, root_ind+1, in_r);
        return root;
    }
};
