class Solution{
	public:
	vector<string> AllPossibleStrings(string s){
	    int n=s.size();
	    vector<string> ans;
	    for(int i=0;i<(1<<n);i++){
	        string output="";
	        for(int j=0;j<n;j++){
	            if(i&(1<<j)){
	                output.push_back(s[j]);
	            }
	        }
	        if(output.size()>0){
	            ans.push_back(output);
	        }
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};
