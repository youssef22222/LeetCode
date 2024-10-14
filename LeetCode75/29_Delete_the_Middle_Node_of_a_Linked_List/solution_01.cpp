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
 int listLength(ListNode * head,int len){
        if(head==nullptr){
           return len;
        }
        return listLength(head->next,len+1);
    }
    ListNode* deleteMiddle(ListNode* head) {
       int len=listLength(head,0);
       int pos=1;
       ListNode * temp=head;
       while(pos<len/2){
        temp=temp->next;
        pos++;
       }
       if(temp->next!=nullptr){
        temp->next=(temp->next)->next;
       }else{
        return nullptr;
       }
       return head;
    }
};