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

 void inorder(TreeNode* root,vector<int>&res)
    {
        TreeNode* temp = root;

        if(root)
        {
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);

        }
    }
    vector<int> preorderTraversal(TreeNode* root) {

         vector<int>res; 
        if(root==nullptr) return res;

        inorder(root,res);

        return res; }
int main()
{
    // insert the value as per the users choice
}