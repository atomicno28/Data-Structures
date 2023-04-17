#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int miniplatform(vector<int>&arr, vector<int>&dep, int n)
{
    // sort both the arrays.
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());


        // Two Pointers
        int i=1,j=0;
    	int answer=1,temp=1;
    	int comp=dep[0];
    	while(i<n && j<n)
    	{
            // if arrival is before the departure of previous.
    	    if(arr[i]<=comp)
    	    {
    	        temp++;
    	        i++;
    	        answer = max(answer,temp);
    	    }
    	    else
    	    {
    	        comp = dep[++j];
    	        temp--;
    	    }
    	}
    	return answer;
}
int main()
{
    int n; cin>>n;

    vector<int> arrival(n,0);
    vector<int> departure(n,0);

    for(int i=0;i<n;i++) cin>>arrival[i];
    for(int i=0;i<n;i++) cin>>departure[i];

    cout<< miniplatform(arrival,departure,n);


}