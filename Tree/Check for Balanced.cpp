#include<iostream>
#include<vector>
using namespace std;

//leetcode

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  bool check(TreeNode * temp)
  {
    if(temp==nullptr) return 0;

    int l=check(temp->left);
    if(l==-1) return -1;
    int r = check(temp->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return 1 + max(l,r);

  }
  bool isBalanced(TreeNode * temp)
  {
      return check(temp)!=-1;
  }
 
int main()
{
    // insert the value as per the users choice
}