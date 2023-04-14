#include<iostream>
#include<vector>
using namespace std;
bool lemonadeChange(vector<int>& bills) {

        int f=0,t=0;

        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5) f++;
            else if(bills[i]==10)
            {
                if(f<1) return 0;
                f--;
                t++;
            }
            else if(bills[i]==20)
            {
                if(f==0) return 0;
                if(t==0 && (5*f)<bills[i]-5) return 0;
                if((5*f)+(10*t)<(bills[i]-5)) return 0;

                t--;f--;
            }

        }

        return 1;
        
    }
int main()
{
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];
  
   cout << (lemonadeChange(v))? "YES":"NO";
    
}