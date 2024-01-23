//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solveMem(int ind,int arr[],int n,vector<int> &dp){
        if(ind==0){
            return arr[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take=arr[ind]+solveMem(ind-2,arr,n,dp);
        int skip=0+solveMem(ind-1,arr,n,dp);
        return dp[ind]=max(take,skip);
    }
    int solveTab(int arr[],int n){
        vector<int> dp(n,0);
        dp[0]=arr[0];
        for(int ind=1;ind<n;ind++){
            int take=arr[ind];
            if(ind>1){
                take+=dp[ind-2];
            }
            int skip=0+dp[ind-1];
            dp[ind]=max(take,skip);
        }
        return dp[n-1];
    }
    int solveSpace(int arr[],int n){
        int prev2=0;
        int prev=arr[0];
        for(int ind=1;ind<n;ind++){
            int take=arr[ind];
            if(ind>1){
                take+=prev2;
            }
            int skip=0+prev;
            int curr=max(take,skip);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int FindMaxSum(int arr[], int n)
    {
        // if(n==1){
        //     return arr[0];
        // }
        // vector<int> dp(n,-1);
        // return solveMem(n-1,arr,n,dp);
        
        // return solveTab(arr,n);
        
        return solveSpace(arr,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
