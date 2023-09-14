//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int largestpowertillN(int N){
        int x=0;
        while((1<<x)<=N){
            x++;
        }
        return x-1;
    }
    int countBits(int n){
        if(n==0){
            return 0;
        }
        int x=largestpowertillN(n);
        int bitsupto2raisetox=x*(1<<(x-1));
        int msbtilln=n-(1<<x)+1;
        int ans=countBits(n-(1<<x))+bitsupto2raisetox+msbtilln;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
