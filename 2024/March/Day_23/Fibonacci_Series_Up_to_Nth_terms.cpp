class Solution {
  public:
    #define ll long long int 
    #define mod 1000000007
    vector<int> Series(int n) {
        // Code here
        vector<int> dp(n+1,0);
        dp[0]=0;dp[1]=1;
        for(ll i=2;i<=n;i++){
            dp[i]=((dp[i-1])%mod+(dp[i-2])%mod)%mod;
        }
    return dp;
    }
};
