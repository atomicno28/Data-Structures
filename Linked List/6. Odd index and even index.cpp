#include<iostream>
using namespace std;
 struct ListNode  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 typedef struct ListNode ListNode;
ListNode* OddEvenShift(ListNode* head) {

        if(!head  || !head->next || !head->next->next)  return head;

        ListNode * oddhead=head; 
        ListNode * odd=head; 
        ListNode * evenhead=head->next;
        ListNode * even=head->next;

        while(even && even->next)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even = even->next;
        }

        odd->next=evenhead;
        return oddhead;

    }
int main()
{
    // implementation is already introduced!

    ListNode * head;

   ListNode * rev = OddEvenShift(head);

    
}