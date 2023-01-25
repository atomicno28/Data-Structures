#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;
    int k; cin>>k;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];
    
    int i=0,j=0,sum=0,mx=-1e9;
    while(j<n)
    { 
        sum+=v[j];
    
        // Case 1
        if(sum<k) j++;
        else
        {

        // Case 2
        if(sum==k) mx=(j-i+1>mx)?j-i+1:mx;

        // Case 3
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=v[i];
                i++;
            }
        }

        j++;
        
        }
    }
    
    cout<<  mx;
}