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
 
int MaxDepth(TreeNode*root)
{
   if(root==nullptr) return 0;

   int l = MaxDepth(root->left);
   int r = MaxDepth(root->right);
   
   return 1 + max(l,r);
}

int main()
{
 // code whatsoever we want!
}