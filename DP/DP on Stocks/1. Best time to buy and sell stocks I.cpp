#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int lowest = prices[0];
    int ans = 0;
    
    for(int i=1;i<prices.size();i++)
    {
        int temp = prices[i] - lowest;
        ans = max(ans,temp);
        lowest = min(lowest,prices[i]);
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];

    cout<< maxProfit(prices);
}