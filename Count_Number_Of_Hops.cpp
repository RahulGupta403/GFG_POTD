//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long int mod=(int)1e9+7;
    long long int solveMem(int ind,vector<long long int>&dp){
        if(ind==0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        long long int jump1=solveMem(ind-1,dp);
        long long int jump2=0;
        if(ind>1){
            jump2=solveMem(ind-2,dp);
        }
        long long int jump3=0;
        if(ind>2){
            jump3=solveMem(ind-3,dp);
        }
        return dp[ind]=((jump1+jump2+jump3)%mod)%mod;
    }
    long long int solveTab(int n){
        long long int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod+dp[i-3]%mod);
        }
        return dp[n]%mod;
    }
    long long int solveSpaceOptimized(int n){
        if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        long long int jump0=1;
        long long int jump1=1;
        long long int jump2=2;
        long long int sum=0;
        for(int i=3;i<=n;i++){
            sum=(jump1+jump2+jump0)%mod;
            jump0=jump1%mod;
            jump1=jump2%mod;
            jump2=sum%mod;
        }
        return jump2%mod;
    }
    long long countWays(int n)
    {
        // vector<long long int>dp(n+1,-1);
        // return (1LL*solveMem(n,dp))%mod;
        
        // return (1LL*solveTab(n))%mod;
        
        return (1LL*solveSpaceOptimized(n))%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
