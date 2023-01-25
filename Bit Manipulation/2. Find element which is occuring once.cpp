#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;
    int result=0;
    vector<int> v(n);
    
    // just do the XOR of all the elements!
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        result^=v[i];
    }
    
    cout <<result;
}