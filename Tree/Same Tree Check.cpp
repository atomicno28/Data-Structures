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
  bool check(TreeNode * temp1, TreeNode * temp2)
  {
       if(!temp1 && !temp2) return 1;
       if(!temp1 && temp2!=nullptr || temp1!=nullptr && !temp2) return 0;

       bool l = check(temp1->left,temp2->left);
       bool r = check(temp1->right,temp2->right);

       if(l && r && temp1->val == temp2->val) return 1;
       else return false;

  }
  bool isSame(TreeNode * temp1, TreeNode * temp2)
  {
      return check(temp1,temp2);
  }
 
int main()
{
    // insert the value as per the users choice
}