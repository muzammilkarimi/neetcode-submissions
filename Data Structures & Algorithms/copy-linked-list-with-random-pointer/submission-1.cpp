/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* curr = head;
        while(curr){
            Node * newnode = new Node(curr->val);
            newnode->next = curr -> next;
            curr -> next = newnode;
            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};
