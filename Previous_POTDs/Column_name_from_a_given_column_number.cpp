//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int columnNumber)
    {
        string ans="";
        unordered_map<int,char> map; 
        map.insert({0,'$'}); 
        for(int i=1;i<=26;i++){
            map[i]=char(i+64);
        }
        if(columnNumber>=1 && columnNumber<=26){
            ans+=map[columnNumber];
            return ans;
        }
        while(columnNumber){
                int remainder=(columnNumber-1)%26;
                ans+=map[remainder+1];
                columnNumber=(columnNumber-1)/26;     
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends
