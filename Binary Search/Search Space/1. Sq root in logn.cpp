#include<iostream>
using namespace std;
int main()
{
    int n; cin>>n;

    int ans =0;

    while(ans*ans<=n) ans++;

    cout << ans-1;
}