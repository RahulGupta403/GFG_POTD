class Solution
{
    public:
    // Complete this function
    #define ll long long int
    ll solve(ll n,ll help[],ll index,ll dp[][3]){
        if(n==0){
            return 1*1LL;
        }
        if(n<0 or index<0){
            return 0;
        }
        if(dp[n][index]!=-1){
            return dp[n][index];
        }
        ll take=solve(n-help[index],help,index,dp);
        ll skip=solve(n,help,index-1,dp);
        return dp[n][index]=(take+skip);
    }
    long long int count(long long int n)
    {
        ll help[3]={3,5,10};
    	ll dp[n+1][3];
    	memset(dp,-1,sizeof(dp));
    	return solve(n,help,2,dp);
    }
};
