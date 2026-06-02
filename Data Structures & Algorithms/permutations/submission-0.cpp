class Solution {
public:
    struct Node{
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
    };
    void dfs(vector<vector<int>>& res, vector<int>& permutation, Node* head){
        if(!head->next){
            res.push_back(permutation);
            return;
        }
        Node* prev = head;
        Node* cur = head->next;
        while(cur){
            prev->next = cur->next;
            permutation.push_back(cur->val);
            dfs(res, permutation, head);
            prev->next = cur;
            permutation.pop_back();
            prev = cur;
            cur = cur->next;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permutaion;
        Node* head = new Node(0);
        Node* ptr = head;
        for(int num: nums){
            ptr-> next = new Node(num);
            ptr = ptr-> next;
        }
        dfs(res, permutaion, head);
        return res;

    }
};
