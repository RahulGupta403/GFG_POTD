class Solution
{
    public:
    int solveMem(int index,vector<int>&prices,int buy,int capacity,
    vector<vector<vector<int>>>&dp){
        if(index>=prices.size() or capacity==0){
            return 0;
        }
        if(dp[index][buy][capacity]!=-1){
            return dp[index][buy][capacity];
        }
        int profit;
        if(buy==0){
            profit=max(solveMem(index+1,prices,buy,capacity,dp),
            -prices[index]+solveMem(index+1,prices,!buy,capacity,dp));
        }
        if(buy==1){
            profit=max(solveMem(index+1,prices,buy,capacity,dp),
            prices[index]+solveMem(index+1,prices,!buy,capacity-1,dp));
        }
    return dp[index][buy][capacity]=profit;
    }
    int maxProfit(vector<int>&prices){
        /*
        int n=prices.size();
        int k=2;
        vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2, vector<int>(k + 1, 0)));
        return solveMem(0,prices,0,k,dp);
        */
        
        
        /*
        // Tabulation Code
        int n=prices.size();
        int k=2;
        vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // We can buy the stock
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                    -prices[ind] + dp[ind + 1][1][cap]);
                    }
    
                    if (buy == 1) { // We can sell the stock
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                    prices[ind] + dp[ind + 1][0][cap - 1]);
                    }
                }
            }
        }
        return dp[0][0][k];
        */
        // Space Optimised Code
        int n=prices.size();
        int k=2;
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // We can buy the stock
                        cur[buy][cap] = max(0 + ahead[0][cap],
                                           -prices[ind] + ahead[1][cap]);
                    }
                    if (buy == 1) { // We can sell the stock
                        cur[buy][cap] = max(0 + ahead[1][cap],
                                           prices[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            // Update the 'ahead' array with the current values
            ahead = cur;
        }
    return ahead[0][k];
    }
};
