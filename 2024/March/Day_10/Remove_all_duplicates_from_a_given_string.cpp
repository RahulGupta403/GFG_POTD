//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char,int> map;
	    string ans="";
	    int n=str.length();
	    for(int i=0;i<n;i++){
	        if(map.find(str[i])==map.end()){
	         ans+=str[i];
	         map[str[i]]++;
	        }
	    }
	  return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
