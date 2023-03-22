#include<iostream>
using namespace std;
 struct ListNode  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

typedef struct ListNode ListNode;

ListNode * loopdetect(ListNode * head)
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

        if(slow==fast)
        {
            while(head!=slow)
            {
                slow=slow->next;
                head=head->next;
            }

            return head;
        }
    }

    return NULL;
}

int main()
{
   ListNode * head;

   ListNode * LoopStart = loopdetect(head);

}