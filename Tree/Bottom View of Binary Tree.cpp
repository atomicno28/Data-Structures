#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  vector<int> BottomView(TreeNode * root)
  {
    vector<int> res;
    if(!root) return res;

    queue<pair<TreeNode*,int>>q;
    
    map <int,int> mp;
    
    q.push({root,0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode * temp = it.first;
        
        int line = it.second;
        
        // it will hold last appearing element of the line
        mp[line] = temp->val;

        if(temp->left) q.push({temp->left,line-1});
        
        if(temp->right) q.push({temp->right,line+1});

    }

    for(auto i: mp)
    {
        res.push_back(i.second);
    }
    
    return res;

  }

int main()
{
    // whatever the code demands!
}