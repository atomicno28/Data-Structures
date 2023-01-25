#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main()
{
    int n,k; cin>>n>>k;
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin>>v[i];

    //to store negative values
    deque<int>dq;

    int i=0,j=0;
    while(j<n)
    {
       if(v[j]<0) dq.push_back(v[j]);
       
       if(j-i+1<k) j++;
       else if(j-i+1==k)
       {
         // if no negative in the sub-array
         if(dq.size()==0) cout<<0<<" "; 
         
         else
         {
            cout<<dq[0]<<" ";
         }

        // if next sub array doesnt contain dq[0]
         if(v[i]==dq[0]) dq.pop_front();

         //slide 
         i++;j++;
       }
    }

}