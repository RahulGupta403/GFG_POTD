class Solution
{
    public:
    int dp[21][21][21] ;
    int solve(string& a , string& b , string& c,int i , int j , int k){
       if(i<0 || j<0 || k<0){
           return 0 ;
       }
       if(dp[i][j][k] != -1){
           return dp[i][j][k] ;
       }
       if((a[i] == b[j])&&(a[i] == c[k])){
           dp[i][j][k] = 1 + solve(a,b,c,i-1,j-1,k-1) ;
       }
       else{
           dp[i][j][k] = max(solve(a,b,c,i-1,j,k),max(solve(a,b,c,i,j-1,k),solve(a,b,c,i,j,k-1))) ;
       }
       return dp[i][j][k] ;
    }
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        memset(dp,-1,sizeof(dp)) ;
        return solve(A,B,C,n1-1,n2-1,n3-1) ;
    }
};
