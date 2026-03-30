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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if (!head->next) return head;
        ListNode * curr = head;
        ListNode* pre = NULL;
        while(curr and curr->next){
            ListNode* nxt = curr->next;
            curr ->next = pre;
            pre = curr;
            curr = nxt;
        }
        curr->next=pre;
        return curr;
    }
};
