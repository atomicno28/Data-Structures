#include<iostream>
#include<vector>
using namespace std;

//space optimised code of MaxSUM SubArray non-adjacent!
int algo(vector<int> &nums)
{
    int n= nums.size();
    int prev=nums[0];
    int prev2=0;

    for(int i=1;i<n;i++)
    {
        int take= nums[i];
        if(i>1) take += prev2;
        int nontake = 0 + prev;

        int curr= max(take,nontake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int houserobber(vector<int> &v){
    int n=v.size();
    if(n==1) return v[0];
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(v[i]);
        if(i!=n-1) temp2.push_back(v[i]);
    }

    return max(algo(temp1),algo(temp2));
}
int main(){
    int n; cin>>n; vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i];
    cout<< houserobber(v);
}