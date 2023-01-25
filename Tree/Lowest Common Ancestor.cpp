#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
TreeNode * LCA (TreeNode * root, TreeNode*p, TreeNode*q)
{
    if(!root || root==p || root==q) return root;

    TreeNode * leftt = LCA(root->left,p,q);
    TreeNode * rightt= LCA(root->right,p,q);

    if(!leftt) return rightt;
    else if(!rightt) return leftt;
    else return root;
}
int main()
{
    //
}
