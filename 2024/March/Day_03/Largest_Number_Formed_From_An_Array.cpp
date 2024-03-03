class Solution{
public:
	static bool comp(string a,string b){
	    return (a+b)>(b+a);
	}
	string printLargest(int n, vector<string> &arr) {
	    string ans="";
	    sort(arr.begin(),arr.end(),comp);
	    for(int i=0;i<n;i++){
	        ans+=arr[i];
	    }
	return ans;
	}
};
