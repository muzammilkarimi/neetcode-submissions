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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = l2;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* l1 = head;
        while(l1 and prev){
            ListNode* temp1 = l1->next;
            ListNode* temp2 = prev->next;
            l1->next = prev;
            prev->next = temp1;
            l1 = temp1;
            prev = temp2;
        }

    }
};
