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

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2){
        while(l1 && l2){
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;

            l1->next=l2;
            l2->next=p1;
            l1=p1;l2=p2;
        }
    }

    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* node = slow->next;
        slow->next=NULL;
        ListNode* l1 = head;
        ListNode* l2 = reverse(node);
        merge(l1,l2);
    }
};