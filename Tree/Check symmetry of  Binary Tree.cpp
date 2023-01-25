#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
    bool check(TreeNode * l,TreeNode * r)
    {
        if(!l || !r ) return l == r;

        if(l->val != r->val) return false;

        return check(l->left,r->right) && check(l->right,r->left);
    }
   bool symmetry(TreeNode*root)
   {
     return !root || check(root->left,root->right);
   }

int main()
{
  // code as per the interest of users!  
}