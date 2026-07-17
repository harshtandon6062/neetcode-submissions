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

bool lca(TreeNode *root, TreeNode*p, TreeNode *q, TreeNode * &res){
    if(!root)return false;
    bool left = lca(root->left, p, q, res), right = lca(root->right, p, q, res);
    if ((left + right + (root == p) + (root == q) >1) & !res) res = root;
    return left || right ||  (root == p) || (root == q);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = nullptr;
        lca(root, p, q, res);
        return res;
    }
};
