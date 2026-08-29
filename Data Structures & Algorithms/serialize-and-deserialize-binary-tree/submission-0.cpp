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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        ser_helper(root, res);
        return res;
    }

    void ser_helper(TreeNode * root, string &res){
        if(root == nullptr){
            res.push_back('#');
            return;
        }
        res.push_back('@');
        res += to_string(root->val);
        ser_helper(root->left, res);
        ser_helper(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return deser_helper(data, i);
    }
    TreeNode* deser_helper(string& data, int &i){
        if(data[i] == '#'){
            i++;
            return nullptr;
        }
        int val_end = i+1;
        while(data[val_end] != '@' && data[val_end] != '#')val_end++;
        TreeNode* root = new TreeNode(stoi(data.substr(i+1, val_end-i-1)));
        i = val_end;
        root->left = deser_helper(data, i);
        root->right = deser_helper(data, i);
        return root;
    }
};
