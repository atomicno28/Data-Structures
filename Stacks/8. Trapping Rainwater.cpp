#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
    
       vector<int>maxl;
       vector<int>maxr;

       int maxi=-1e9;
       for(int i=0;i<height.size();i++)
       {
         if(maxi<height[i]) maxi=height[i];
         maxl.push_back(maxi); 
       }
       maxi=-1e9;
       for(int i=height.size()-1;i>=0;i--)
       {
           if(maxi<height[i]) maxi=height[i];
           maxr.push_back(maxi);
       }
       reverse(maxr.begin(),maxr.end());

       int ans=0;

       for(int i=0;i<height.size();i++)
       {
         ans+= (min(maxl[i],maxr[i])-height[i]);
       }

       return ans;
    }
int main()
{
    int n; cin>>n;
    vector<int> height(n);
    
    for(int i=0;i<n;i++) cin>>height[i];
    
    cout << trap(height);
}