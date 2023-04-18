/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *one)
    {
        int cnt=0;
        while(one->next!=NULL){
            cnt++;
            one=one->next;
        }
        return cnt+1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return NULL;
        int l1=getLength(headA);
        int l2=getLength(headB);
        int d=abs(l1-l2);
        ListNode*temp1;
        ListNode*temp2;
        if(l2>l1){
            temp1=headB;
            temp2=headA;
        }else{
            temp1=headA;
            temp2=headB;

        }
        while(d){
            temp1=temp1->next;
            if(!temp1)return NULL;
            d--;
        }
        while(temp1!=NULL and temp2!=NULL){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};