#include<iostream>
#include<vector>
using namespace std;
 int longestPalindrome(string s) {
        
        if(s.size()==1) return 1;

        int arr[256]={0};

        for(int i=0;i<s.size();i++) arr[s[i]]++;

        int count=0;

        for(int i=0;i<256;i++)
        {
            if(arr[i]&1) count++;
        }

        if(count>1) return s.size() + 1 - count;
        return s.size();
    }
int main()
{
    string s;

    cout << longestPalindrome(s);
}