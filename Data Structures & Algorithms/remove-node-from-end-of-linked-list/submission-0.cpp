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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *node = head;
        while(node){
            len++;
            node = node->next;
        }
        int i = len - n;
        ListNode *dummy = new ListNode(0,head);
        ListNode *prev = dummy;
        while(i--) prev = prev->next;
        prev->next = prev->next->next;
        return dummy->next;
    }
};
