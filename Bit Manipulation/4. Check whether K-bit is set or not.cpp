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

    // remember indexing starts from ( n-1 .... 0 )

    cout << checker(n,k);
}