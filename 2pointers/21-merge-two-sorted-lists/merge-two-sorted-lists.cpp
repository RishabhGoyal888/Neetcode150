// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(-1);
//         ListNode* curr = dummy;
//         while(l1 && l2){
//             if(l1->val <= l2->val){
//                 ListNode* temp = new ListNode(l1->val);
//                 curr->next = temp;
//                 curr = temp;
//                 l1=l1->next;
//             }
//             else{
//                 ListNode* temp = new ListNode(l2->val);
//                 curr->next = temp;
//                 curr = temp;
//                 l2=l2->next;
//             }
//         }
//         while(l1){
//             ListNode* temp = new ListNode(l1->val);
//             curr->next = temp;
//             curr = temp;
//             l1=l1->next;
//         }
//         while(l2){
//             ListNode* temp = new ListNode(l2->val);
//             curr->next = temp;
//             curr = temp;
//             l2=l2->next;
//         }
//         return dummy->next;
//     }
// };

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1=l1->next;
            }
            else{
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1){
            curr->next = l1;
        }
        if(l2){
            curr->next = l2;
        }
        return dummy->next;
    }
};