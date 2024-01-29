class Solution{
	public:
	int help(string& s,int i,int pre,vector<vector<int>>& dp)
	{
	    //base case
	    if(i<0){
	        return 1;
	    }
	    if(pre!=-1 and dp[i][pre]!=-1){
	        return dp[i][pre];
	    }
	    int sum=0;
	    int ans=0;
	    string str="";
	    for(int j=i;j>=0;j--)
	    {
	        sum+=s[j]-'0';
	        if(sum<=pre or pre==-1){
	            ans+=help(s,j-1,sum,dp);
	        }
	        else
	            break;
	    }
	    if(pre==-1){
	        return ans;
	    }
	    return dp[i][pre]=ans;
	}
	int TotalCount(string str){
	    vector<vector<int>> dp(str.length()+1,vector<int>(1000,-1));
	    return help(str,str.length()-1,-1,dp);
	}
};
