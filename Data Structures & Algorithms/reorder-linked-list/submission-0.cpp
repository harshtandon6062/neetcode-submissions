/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> st;
        int n = 0; ListNode* node = head;
        while(node){
            n++;
            node = node->next;
        }
        node = head;
        for(int i = 0; i < n/2; i++){
            st.push_back(node);
            node=node->next;
        }
        ListNode* mid = nullptr;
        if(n%2) mid = node;
        ListNode* left, * right = (n%2) ? node->next : node;
        if(mid) mid->next = nullptr;
        for(int i = 0; i < n/2; i++){
            left = st.back(); st.pop_back();
            ListNode* next_right = right->next;
            right->next = mid;
            left->next = right;
            mid = left;
            right = next_right;
        }
    }
};
