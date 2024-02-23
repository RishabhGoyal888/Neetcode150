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
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr= curr->next->next;
        }

        curr= head;
        while(curr){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* oldHead = head;
        Node* newHead = head->next;
        curr = head->next;

        while(curr){
            oldHead->next = oldHead->next->next;
            if(curr->next == NULL){
                curr->next = NULL;
            }
            else{
                curr->next = curr->next->next;
            }
            oldHead=oldHead->next;
            curr=curr->next;
        }
        return newHead;
    }
};