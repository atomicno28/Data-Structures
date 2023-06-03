#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool comp(int a, int b)
{
    string A= to_string(a);
    string B = to_string(b);

    // concatenate and check.
    return A+B>B+A;
}
int main()
{
    int n; cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end(),comp);

    // if the greater element is zero.
    if(v[0]==0) cout<<0;

    for(int i=0;i<n;i++) cout<<v[i];


}