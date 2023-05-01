// In this question we have to find the substring in s.

// Eg
// s = prerajulisation
// p = raju 


// then in such case we have to find 'raju' is present in 'prerajulisation' or not.


#include<iostream>
#include<vector>
using namespace std;
bool KMP(string &s, string&p)
{
    // creating dummy array.
    vector<int> arr(p.size());
    arr[0]=0;
    
    int j=0,i=1;
    while(i<p.size())
    {
        if(p[i]==p[j])
        {
            arr[i]=j+1;
            i++,j++;
        }
        else
        {
            //logic
            if(j) j=arr[j-1];
            else arr[i]=0,i++;
        }
    }
    // dummy array is now created.
    
    i=0,j=0;
    
    // with the help of dummy array we'll do the searching of substring.
    while(i<s.size() && j<p.size())
    {
        if(s[i]==p[j]) i++,j++;
        else
        {
            //logic
            if(j) j=arr[j-1];
            else i++;
        }
    }
    
    // if j reaches to end, then return true
    
    return j==p.size();
}
int main()
{
    string s; cin>>s;
    string p; cin>>p;
    
    if(KMP(s,p)) cout<<"YES";
    else cout<<"NO";
}