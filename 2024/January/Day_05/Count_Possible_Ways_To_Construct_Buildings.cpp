class Solution{
	public:
	int TotalWays(int N){
    long mod = 1e9+7;
    long dp[N+1][2] = {1};    // One combination when N=0
    
    for(int i=1; i<=N; i++){
        // i denotes the current plot number
        for(int j=0; j<2; j++){
            // j denotes that if there is a building on the (i)th plot or not
            // if j==1, there is a building
            // if j==0, there is a space
            if(j) dp[i][j] = dp[i-1][0];
            else dp[i][j] = (dp[i-1][0] + dp[i-1][1]) % mod;
        }
    }
    
    long ans = (dp[N][0] + dp[N][1]); // we will sum both the values to get total combinations
    ans = (ans*ans)%mod; // squaring
    return ans;
    }
};
