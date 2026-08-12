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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode *a, const ListNode *b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq;

        if(lists.empty()) return nullptr;

        for(auto& li: lists) if(li) pq.push(li);
        if(pq.empty()) return nullptr;

        ListNode* res = pq.top(); pq.pop();
        if(res->next) pq.push(res->next);

        ListNode *node = res;
        while(!pq.empty()){
            node->next = pq.top(); pq.pop();
            node = node->next;
            if(node->next)pq.push(node->next);
        }
        return res;
        

    }
};
