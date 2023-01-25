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

  vector<vector<int>> levelorder(TreeNode*root)
  {
    
     vector<vector<int>>res;
     if(root==nullptr) return res;

     queue<TreeNode*> q;

     q.push(root);
     while(!q.empty())
     {
         int n=q.size();
         vector<int>res2;
         for(int i=0;i<n;i++)
         {
             TreeNode * temp = q.front();
             q.pop();
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
             res2.push_back(temp->val);
         }
         res.push_back(res2);
     }

     return res;
  }
int main()
{
    //
}