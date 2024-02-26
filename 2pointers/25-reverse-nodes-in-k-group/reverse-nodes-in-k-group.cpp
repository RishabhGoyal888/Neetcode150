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
    ListNode* findKNode(ListNode* h, int k){
        ListNode* temp = h;
        k=k-1;
        while(temp && k > 0){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* h){
        if(h == NULL || h->next == NULL)
            return NULL;
        ListNode* curr = h;
        ListNode* prev = NULL;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp){
            ListNode* kthNode = findKNode(temp, k);
            if(kthNode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthNode;
            } else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};