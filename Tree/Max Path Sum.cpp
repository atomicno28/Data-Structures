#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

   int maxPathSum(TreeNode*temp, int &val)
   {
       if(!temp) return 0; 

       int l = max(0,maxPathSum(temp->left,val));
       int r = max(0,maxPathSum(temp->right,val));

       val= max(val,l+r+temp->val);

       return temp->val + max(l,r);

   }
   int maxx(TreeNode* root)
   {
    int res=-1e9;
    maxPathSum(root,res);
    return res;
   }

int main()
{
    //
}