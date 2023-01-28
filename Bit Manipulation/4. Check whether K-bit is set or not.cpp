#include<iostream>
#include<string>
using namespace std;
string check(int n, int k)
{
    return (n&(1<<k))? "YES":"NO";
}
int main()
{
    int n; cin>>n;
    int k; cin>>k;

    cout << checker(n,k);
}