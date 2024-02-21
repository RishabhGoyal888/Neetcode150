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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* t1=l1;
//         ListNode* t2=l2;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* curr = dummy;
//         int sum=0;
//         int carry=0;
//         while(t1 && t2){
//             sum=t1->val + t2->val + carry;
//             ListNode* temp=new ListNode(sum%10);
//             curr->next = temp;
//             curr=temp;
//             carry=sum/10;
//             sum=0;
//             t1=t1->next;
//             t2=t2->next;
//         }
//         while(t1){
//             sum=t1->val + carry;
//             ListNode* temp=new ListNode(sum%10);
//             curr->next = temp;
//             curr=temp;
//             carry=sum/10;
//             sum=0;
//             t1=t1->next;
//         }
//         while(t2){
//             sum=t2->val + carry;
//             ListNode* temp=new ListNode(sum%10);
//             curr->next = temp;
//             curr=temp;
//             carry=sum/10;
//             sum=0;
//             t2=t2->next;
//         }
//         if(carry){
//             ListNode* temp=new ListNode(carry);
//             curr->next = temp;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int sum=0;
        int carry=0;
        while(t1 || t2){
            sum=carry;
            if(t1) sum = sum + t1->val;
            if(t2) sum = sum + t2->val;
            ListNode* temp=new ListNode(sum%10);
            curr->next = temp;
            curr=temp;
            carry=sum/10;
            sum=0;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        
        if(carry){
            ListNode* temp=new ListNode(carry);
            curr->next = temp;
        }

        return dummy->next;
    }
};