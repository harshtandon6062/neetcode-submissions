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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        ListNode *prv = nullptr;
        ListNode *cur = head;
        ListNode *nxt = head->next;
        for(int i = 0; i < size/2; i++){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        ListNode *first = prv;
        ListNode *second = cur;
        for(int i = 0; i < size%2; i++) second = second->next;
        while(first){ //or second
            if(first->val != second-> val) return false;
            first = first->next;
            second = second->next;
        }
        return true;

    }
};