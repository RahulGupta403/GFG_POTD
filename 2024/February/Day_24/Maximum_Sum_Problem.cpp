class Solution
{
    public:
    int solve(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int sum=solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp);
        return dp[n]=max(sum,n);
    }
    int maxSum(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
