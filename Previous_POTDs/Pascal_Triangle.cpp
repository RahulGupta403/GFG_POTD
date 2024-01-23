class Solution{
public:
    #define ll long long 
    int mod=(int)1e9+7;
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> ans(n);
        for(ll i=0;i<n;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(ll j=1;j<i;j++){
                ans[i][j]=((ans[i-1][j-1]+ans[i-1][j])%mod)%mod;
            }
        }
        return ans[n-1];
    }
};
