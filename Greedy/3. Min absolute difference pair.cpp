#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n; cin>>n;
    
    vector<int> a(n);
    vector<int> b(n);

    for(auto i:a) cin>>i;
    for(auto i:b) cin>>i;

    // sort both the arrays..
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int profit=0;

    for(int i=0;i<n;i++)
    {
        profit += abs(a[i]-b[i]);
    }

    cout<< profit;
}