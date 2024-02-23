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
// //with extra space
// class Solution {
// public:
//     //with extra space
//     Node* copyRandomList(Node* head) {
//         if (head == NULL) {
//             return NULL;
//         }

//         Node* curr = head;
//         unordered_map<Node*, Node*> mp;
//         while(curr){
//             mp[curr] = new Node(curr->val);
//             curr=curr->next;
//         }

//         curr = head;
//         Node* newHead = mp[curr];
//         Node* temp = newHead;
//         while(curr){
//             temp->next = mp[curr->next];
//             temp->random = mp[curr->random];
//             temp=temp->next;
//             curr=curr->next;
//         }
//         return newHead;
//     }
// };

//  without extra space
//=========================
// original List:  A->B->C->D
// updating it to: A->a->B->b->C->c->D->d
// then separating both list and returning the copy list a->b->c->d
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        while(curr){ //updating list with value and next pointer
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr= curr->next->next;
        }

        curr= head;
        while(curr){ //updatin list with random pointer also
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        } //list is complete, now need to seperate both lists, and return the required one

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