#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s; cin>>s;

    int n = s.size();

    vector<int> arr(n);

    bool flag=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]=='0') flag=1,arr[i]=1;
        else arr[i]=-1;
    }

    // if string doesnt contain the 0;
    if(flag) return 0;

    int curr=0,maxi=0;
    int left=0;
    int right=0;

    vector<int> ans(2);
    for(int i=0;i<n;i++)
    {
          curr+= arr[i];

          if(curr>maxi) maxi=curr,right=i,ans[0]=left+1,ans[1]=right+1;

          if(curr<0) curr=0,left=i+1;
    }

    cout<<ans[0]<<"  "<<ans[1];

}