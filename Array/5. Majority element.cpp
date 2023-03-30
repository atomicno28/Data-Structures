#include<iostream>
#include<vector>
using namespace std;
int main()
{
      int n; cin>>n;
      vector<int> arr(n);

      for(int i=0;i<n;i++) cin>>arr[i];

      int curr = arr[0];
      int count=0;

      for(auto i:arr)
      {
        if(count==0) curr=i;
        count += (curr==i)?1:-1;
      }

      cout << curr;
}