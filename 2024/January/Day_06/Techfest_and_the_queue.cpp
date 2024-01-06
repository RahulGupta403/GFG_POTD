//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   int help(int a)
    {
        int cnt=0;
        for(int i=2;i*i<=a;i++)
        {
            while(a%i==0)
            {
                cnt++;
                a/=i;
            }
        }
        
        if(a>1)
        cnt++;
        return cnt;
    }
	int sumOfPowers(int a, int b){
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int cnt=help(i);
	        ans+=cnt;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
