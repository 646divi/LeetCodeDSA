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
//     ListNode *temp;
//     ListNode *LinkedListReverse(ListNode *head,int right,int cnt){
        
//         if(cnt==right){
//             temp=head->next;
//             return head;
//         }
//         if(!head || !head->next)return head;
        
//         ListNode * node=LinkedListReverse(head->next,right,cnt+1);
//         head->next->next=head;
//         head->next=NULL;
//         return node;
//     }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head and !head->next|| left==right)return head;
        ListNode* dummy=new ListNode(-1);
        // dummy->next=head;
        ListNode *prev=dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* tail=prev->next;
        for(int i=0;i<(right-left);i++){
            ListNode * temp=prev->next;
            prev->next=tail->next;
            tail->next=tail->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
//         int cnt=1;
//         ListNode *curr=head;
//         while(true){
//             if(cnt+1 == left || cnt==left){
//                 curr->next=LinkedListReverse(curr->next,right,cnt+1); 
//                 // break;
//             }
//             curr=curr->next;
//             cnt++;
//             if(cnt==right){
//                 curr->next=temp;
//                 break;
//             }
            
//         }
//         return head;
    }
};