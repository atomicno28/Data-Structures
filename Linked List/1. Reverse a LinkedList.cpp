#include<iostream>
using namespace std;
 struct ListNode  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 typedef struct ListNode ListNode;
ListNode* reverseList(ListNode* head) {

        if(head==nullptr)  return nullptr;

        ListNode * revHead=head;

        int flag=1;

        while(head)
        {
            ListNode * neww = new ListNode(head->val);

            if(flag) {revHead=neww; flag--;}
            else 
            {
                neww->next=revHead;
                revHead=neww;
            }
            head=head->next;
        }

        return revHead;
    }
int main()
{
    // implementation is already introduced!

    ListNode * head;

   ListNode * rev = reverseList(head);

    
}