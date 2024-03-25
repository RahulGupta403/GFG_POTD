class Solution{
public:	
    void solve(int ones,int zeros,int n,vector<string>&ans,string op){
        if(n==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        op1+='1';
        solve(ones+1,zeros,n-1,ans,op1);
        if(ones>zeros){
            string op1=op;
            op1+='0';
            solve(ones,zeros+1,n-1,ans,op1);
        }
    }
	vector<string> NBitBinary(int n)
	{
	    string op="";
	    vector<string> ans;
	    int ones=0,zeros=0;
	    solve(ones,zeros,n,ans,op);
	    return ans;
	}
};



// More Efficient and Readable Code
class Solution{
public:	
    void solve(int ones,int zeros,int n,vector<string>&ans,string op){
        if(n==0){
            ans.push_back(op);
            return;
        }
        solve(ones+1,zeros,n-1,ans,op+'1');
        if(ones>=zeros+1){
            solve(ones,zeros+1,n-1,ans,op+'0');
        }
    }
	vector<string> NBitBinary(int n)
	{
	    string op="";
	    vector<string> ans;
	    int ones=0,zeros=0;
	    solve(ones,zeros,n,ans,op);
	    return ans;
	}
};
