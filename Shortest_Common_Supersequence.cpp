class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int solve(string x,string y,int i,int j,vector<vector<int>> &dp){
        if(i<=0 and j<=0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=1 and j>=1 and x[i-1]==y[j-1]){
            return dp[i][j]=1+solve(x,y,i-1,j-1,dp);
        }
        int min1=1e9;
        int min2=1e9;
        if(i>=1){
            min1=1+solve(x,y,i-1,j,dp);
        }
        if(j>=1){
            min2=1+solve(x,y,i,j-1,dp);
        }
        return dp[i][j]=min(min1,min2);
    }
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(x,y,m,n,dp);
    }
};
