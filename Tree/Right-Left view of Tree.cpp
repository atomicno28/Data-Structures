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
  void algo(int level,vector<int>&res,TreeNode * root)
  {
    if(!root) return;
    if(level==res.size()) res.push_back(root->val);
    algo(level+1,res,root->right);
    algo(level+1,res,root);

  }
  vector <int> RightView(TreeNode*root)
  {
    vector<int>res;
    algo(0,res,root);
    return res;
  }

int main()
{
  // code as per the interest of users!  
}