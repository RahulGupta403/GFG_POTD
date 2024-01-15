class Solution{
    public:
    int solve(int ind,int total,vector<int>&cost,int n, vector<vector<int>>&dp){
        if(ind==n)
          return 0;
        if(dp[ind][total]!=-1) 
          return dp[ind][total];
        int notpick=solve(ind+1,total,cost,n,dp);
        int pick=0;
        if(cost[ind]<=total)
          pick=1+solve(ind+1,total-cost[ind]+(cost[ind]*9)/10,cost,n,dp);
        return dp[ind][total]=max(pick,notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return solve(0,total,cost,n,dp);
    }
};
