#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
typedef struct Node Node;
Node * remDup(Node * head)
{
    // Two Pointer Approach.
    Node * left, *right;

    left=head,right=head;

    while(right)
    {
        if(left->data==right->data) right=right->next;
        else left->next=right,right->prev=left,left=right;
    }

    left->next=nullptr;
    return head;
}
int main()
{
    Node * temp;
    // further creation and many thing;

    Node * result = remDup(temp);
}