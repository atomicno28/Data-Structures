#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;

    vector<vector<int>> arr(m,vector<int>(n));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<i;j++)  swap(arr[i][j],arr[j][i]);
    }

    for(int i=0;i<m;i++) reverse(arr[i].begin(),arr[i].end());

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
