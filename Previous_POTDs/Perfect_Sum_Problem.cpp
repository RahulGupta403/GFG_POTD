//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int mod=(int)1e9+7;
    int solve(int index,int target,int arr[],int n,vector<vector<int>>&dp){
        if(target<0){
            return 0;
        }
        if(index==n){
            if(target==0){
            return 1;
            }
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int skip=solve(index+1,target,arr,n,dp);
        int take=solve(index+1,target-arr[index],arr,n,dp);
        return dp[index][target]=(take + skip)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
	    int target=sum;
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,target,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
