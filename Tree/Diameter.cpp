#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 int diameteralgo(int &maxi, TreeNode * root)
 {
    if(!root) return 0;

    int l = diameteralgo(maxi,root->left);
    int r = diameteralgo(maxi,root->right);

    maxi = max(maxi,l+r);

    return root->val + max(l,r);
 }
 int diameter(TreeNode * root)
 {
    int maxi=0;
    diameteralgo(maxi,root);
    return maxi;
 }

int main()
{
    //
}