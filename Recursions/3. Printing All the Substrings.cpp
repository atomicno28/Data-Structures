#include<iostream>
#include<vector>
using namespace std;
void subsq(string s, int i, int n, string&temp)
{
    if(i==n)
    {
        for(int i=0;i<temp.size();i++) cout<<temp[i];
        cout<<endl;
        return;
    }
    
   //pick
    temp+=s[i]; 
    subsq(s,i+1,n,temp);
    temp.pop_back();
    
    //notpick
    subsq(s,i+1,n,temp);
}
int main()
{
   string s;
   cin>>s;
   
   string temp="";
   
   subsq(s,0,s.size(),temp);
}