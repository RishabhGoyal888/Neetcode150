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
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* a = NULL;   
        ListNode* b = head;
        ListNode* c = head->next;
        while(b){
            b->next = a;
            a=b;
            b=c;
            if(c) c=c->next;
        }
        return a;
    }
};