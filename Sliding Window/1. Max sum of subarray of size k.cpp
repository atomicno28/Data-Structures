#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n; cin>>n;
    int k; cin>>k;

    //if size of k exceeded the size of array!
    if(k>n) return -1;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int i=0,j=0,sum=0,mx=-1e9;
    while(j<n)
    {

        sum+= v[j];

        if(j-i+1<k) j++;

        else if (j-i+1==k)
        {

            //mx will hold the final answer!
            mx= max(mx,sum);

            //reduce the sum by arr of omitted part of array!
            sum-=v[i]; 
            
            //slide
            i++,j++;
        }
    }

   cout<< mx;
}