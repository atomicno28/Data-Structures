#include<iostream>
#include<vector>
#include<utility>
using namespace std;
 void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> coll;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(!matrix[i][j]) coll.push_back({i,j});
            }
        }

        for(auto it: coll)
        {
            for(int i=0;i<matrix[0].size();i++)
            {
                matrix[it.first][i]=0;
            }
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][it.second]=0;
            }
        }
    }
int main()
{
    int m,n; cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    setZeroes(arr);
}