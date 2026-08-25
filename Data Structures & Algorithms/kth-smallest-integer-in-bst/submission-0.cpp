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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode * cur = root;
        int count = 0;
        while(cur != nullptr){
            if(cur->left == nullptr){
                count++;
                if(count == k) return cur->val;
                cur = cur->right;
            }
            else{
                TreeNode *pred = cur->left;
                while(pred->right != nullptr && pred->right != cur) pred = pred->right;
                if(pred->right == nullptr){
                    pred->right = cur;
                    cur = cur->left;
                }
                else if(pred->right == cur){
                    pred->right = nullptr;
                    count++;
                    if(count == k) return cur->val;
                    cur = cur->right;
                }
            }
        }
        return -1;
    }
};
