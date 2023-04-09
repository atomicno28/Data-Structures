#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combsum(int i,int target,vector <int> &candidates,vector <vector <int>> &ans,vector <int> &v){
        if(target==0){
           ans.push_back(v);
            return;
        }
        for(int index=i;index<candidates.size();index++){

            // if adjacents element are equal
            if(index>i && candidates[index]==candidates[index-1]) continue;

            // if sum exceed the target
            if(candidates[index]>target) break;

            //push
            v.push_back(candidates[index]);
            combsum(index+1,target-candidates[index],candidates,ans,v);
            v.pop_back();
        }
    }
int main()
{
    int n; cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());

    int target; cin>>target;

    vector<vector<int>> res;
    vector<int> ds;

    combsum(0,target,v,res,ds);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}