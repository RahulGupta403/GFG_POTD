class Solution{
public:
    vector<int> recamanSequence(int n){
        unordered_set<int> set;
        vector<int> dp(n,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=3;
        set.insert(0);
        set.insert(1);
        set.insert(3);
        for(int i=3;i<n;i++){
            int ans=dp[i-1]-(i);
            if(ans>0 and (set.find(ans)==set.end())){
                dp[i]=ans;
                set.insert(ans);
            }else{
                dp[i]=dp[i-1]+(i);
                set.insert(dp[i]);
            }
        }
    return dp;
    }
};
