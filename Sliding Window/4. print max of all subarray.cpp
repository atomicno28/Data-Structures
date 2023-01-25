#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main()
{
    int n; cin>>n;
    int k; cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    deque<int> dq;

    int i=0,j=0;
    while(j<n)
    {
       while(!dq.empty() && arr[j]>dq.back())
       {
         dq.pop_back();
       }
       dq.push_back(arr[j]);
       if(j-i+1<k) j++;
       else if(j-i+1==k)
       {
        cout<< dq.front() << " ";
        if(arr[i]==dq.front()) dq.pop_front();
        i++;j++;
       }
    }
}