class Solution{
  public:
    int func(int n,int m,string &str1,string &str2,vector<vector<int>> &dp){
        if(n==0 or m==0){
            return 0;
        }
        if(str1[n-1]==str2[m-1]){
            return 1+func(n-1,m-1,str1,str2,dp);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int option1=func(n,m-1,str1,str2,dp);
        int option2=func(n-1,m,str1,str2,dp);        
        return dp[n][m]=max(option1,option2);
    }
    int minimumNumberOfDeletions(string s) { 
        int n=s.size();
        string help=s;
        reverse(begin(help),end(help));
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return n-func(n,n,s,help,dp);
    } 
};
