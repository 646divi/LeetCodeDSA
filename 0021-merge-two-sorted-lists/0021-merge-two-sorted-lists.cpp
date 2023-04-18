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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode * c1=list1;
        ListNode * c2=list2;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(c1!=NULL and c2!=NULL){
            if(c1->val<=c2->val){
                // ListNode * tmp=new ListNode(c1);
                temp->next=c1;
                temp=temp->next;
                c1=c1->next;
            }else{
                // ListNode * tmp=new ListNode(c2);
                temp->next=c2;
                temp=temp->next;
                c2=c2->next;
            }
        }
        if(c1)temp->next=c1;
        if(c2)temp->next=c2;
        
        return dummy->next;
    }
};