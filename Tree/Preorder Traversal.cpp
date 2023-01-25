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

 void pre(TreeNode* root,vector<int>&res)
    {
        TreeNode* temp = root;

        if(root)
        {
            res.push_back(root->val);
            pre(root->left,res);
            pre(root->right,res);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {

         vector<int>res; 
        if(root==nullptr) return res;

        pre(root,res);

        return res;

    }
int main()
{
    // insert the value as per the users choice
}