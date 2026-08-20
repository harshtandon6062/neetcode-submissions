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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int level_size = 1;
        int next_level_size;
        while(!q.empty()){
            next_level_size = 0;
            while(level_size--){
                TreeNode* node = q.front(); q.pop();
                if(node->left){
                    q.push(node->left);
                    next_level_size++;
                } 
                if(node->right){
                    q.push(node->right);
                    next_level_size++;
                }
            }
            level_size = next_level_size;
            level++;
        }
        return level;
    }
};









