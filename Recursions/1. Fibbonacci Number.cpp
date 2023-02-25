#include<iostream>
using namespace std;
int fibbo(int n)
{
	if(n<=1) return n;
	return fibbo(n-1) + fibbo(n-2); // multiple recursive calls;
}
int main()
{
	int n; cin>>n;
 	cout << fibbo(n);  // tc is nearly equal to 2 raised to n;
}
