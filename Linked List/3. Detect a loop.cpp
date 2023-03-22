#include<iostream>
using namespace std;
 struct ListNode  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

typedef struct ListNode ListNode;

bool checkloop(ListNode * head)
{
    if(head==nullptr) return nullptr;

    // we'll follow rabbit(fast) and turtle(slow) approach!
    // rabbit -> 2 steps at a time!
    // turtle -> 1 steps ar a time!

    ListNode * fast = head;
    ListNode * slow = head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast = fast->next->next;

        if(slow==fast) return true;
    }

    return false;
}

int main()
{
   ListNode * head;

   if(checkloop(head)) cout<<"Yes! Loop Exists!";
   else cout<<"No Loop found!";

}