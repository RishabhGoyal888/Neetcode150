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
        if(!head){
            return NULL;
        }
        int m = n;
        ListNode* temp = head;
        while(m){
            m--;
            temp = temp->next;
        }
        if(!temp){
            return head->next;
        }
        ListNode* prev= NULL;
        ListNode* curr=head;
        while(temp){
            prev=curr;
            curr=curr->next;
            temp=temp->next;
        }
        
        if(curr){
            prev->next = curr->next;

        }
        delete curr;
        return head;
    }
};