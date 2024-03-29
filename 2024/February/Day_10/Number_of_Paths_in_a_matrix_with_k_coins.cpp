class Solution {
public:
    #define ll long long
    ll help(vector<vector<int>>& v,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        //base case
        if(i==0 and j==0)
        {
            if((k-v[0][0])==0)
                return 1;
            else
                return 0;
        }
        if(k<0 or k==0 or i<0 or i>=v.size() or j<0 or j>=v[0].size()){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        //recursive calls and small calculation
        ll a=help(v,i-1,j,k-v[i][j],dp);
        ll b=help(v,i,j-1,k-v[i][j],dp);
        return dp[i][j][k]=a+b;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(arr.size(),vector<vector<int>>(arr[0].size(),vector<int>(k+1,-1)));
        ll ans=help(arr,n-1,n-1,k,dp);
        return ans;
    }
};
