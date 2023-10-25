//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    int f(int ind,int w,int val[],int wt[],vector<vector<int>>&dp){
        
       if(ind==0)return 0;
        
        if(dp[ind][w]!=-1)return dp[ind][w];
        
        int take = -1e9;
        if(wt[ind-1]<=w)take = val[ind-1]+f(ind,w-wt[ind-1],val,wt,dp);
        
        int nottake = f(ind-1,w,val,wt,dp);
        return dp[ind][w] = max(take,nottake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        
        // ==>memoization code
        // return f(N,W,val,wt,dp);
        
        // tabulation code==>
        for(int ind=1;ind<=N;ind++){
            for(int w=0;w<=W;w++){
                int take = -1e9;
                if(wt[ind-1]<=w)take = val[ind-1]+dp[ind][w-wt[ind-1]];
                int nottake = dp[ind-1][w];
                dp[ind][w] = max(take,nottake);
            }
        }
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
