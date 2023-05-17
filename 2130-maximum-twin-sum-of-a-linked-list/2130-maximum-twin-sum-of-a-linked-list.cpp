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
    ListNode* reverseLink(ListNode * head){
        ListNode *prev=NULL;
        ListNode *next;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;

    }
    int pairSum(ListNode* head) {
        if(head->next->next==NULL)return head->val+head->next->val;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverseLink(slow->next);
        slow=slow->next;
        fast=head;
        int sum=INT_MIN;
        while(slow){
            sum=max(sum,fast->val+slow->val);
            slow=slow->next;
            fast=fast->next;
        }
        return sum;
    }
};