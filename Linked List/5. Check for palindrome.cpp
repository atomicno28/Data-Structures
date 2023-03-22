#include<iostream>
#include<stack>
using namespace std;
struct ListNode  
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

bool check(ListNode * head, ListNode * temp)
{
    if(head==nullptr) return 1;

    bool res = check(head->next,temp) & (temp->val == head->val);
    temp=temp->next;
    return res;
}

bool palincheck(ListNode * head)
{
    if(head==nullptr) return 0;
    if(head->next == nullptr) return 1;

    // Using Stack.
    // Space (N)
    // stack <int> s;
    // ListNode * temp = head;
    // while(temp)
    // {
    //     s.push(temp->val);
    //     temp=temp->next;
    // }

    // while(head)
    // {
    //     if(s.top()!=head->val) return false;
    //     else s.pop();
    //     head=head->next;
    // }

    // return true;

    // 2. Recursive Approach!
    ListNode * temp=head;
    return check (head,temp);


}

int main()
{
    ListNode * head;

    if(palincheck(head)) cout<<"Yes! Its a Palindrome!";
    else cout<< "Naah! not a palindrome!";
}