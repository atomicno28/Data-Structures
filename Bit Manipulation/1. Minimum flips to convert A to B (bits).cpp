#include<iostream>
using namespace std;
int countSetBits(int n)
{
    int count=0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }

    return count;

}
int main()
{
    int A; cin>>A;
    int B; cin>>B;
    
    // Xor of A and B will consist the number of set bits!
    int store = A^B;

    cout << countSetBits(store);
}