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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* firstOdd=head,*firstEven;
        firstEven=head->next;
        while(temp!=nullptr){
            ListNode* nextNode=temp->next;
            if(nextNode!=nullptr){
               temp->next=nextNode->next;
            }
            temp=nextNode;
        }
        while(firstOdd->next!=nullptr){
            firstOdd=firstOdd->next;
        }
        firstOdd->next=firstEven;
        return head;
    }
};