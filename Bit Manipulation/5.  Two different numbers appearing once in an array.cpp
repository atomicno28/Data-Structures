#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> v(n);


    int temp =0;

    for(int i=0;i<n;i++) cin>>v[i], temp^=v[i];


    // Just do this approach!
    temp = temp & (~(temp-1));

    int a,b; a=b=0;

    for(auto i:v)
    {
        if(temp&i) a^=i;
        else b^=i;
    }

    cout <<a<<" "<<b;



}