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

 void post(TreeNode* root,vector<int>&res)
    {
        TreeNode* temp = root;

        if(root)
        {
            post(root->left,res);
            post(root->right,res);
            res.push_back(root->val);

        }
    }
    vector<int> preorderTraversal(TreeNode* root) {

         vector<int>res; 
        if(root==nullptr) return res;

        post(root,res);

        return res;

    }
int main()
{
    // insert the value as per the users choice
}