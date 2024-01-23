//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        if(n==1){
            return false;
        }
        long long int ans=1;
        for(long long int i=2;i*i<=n;i++){
            if(n%i==0){
                if(i*i!=n){
                    ans=ans+i+n/i;
                }else{
                    ans=ans+i;
                }
            }
        }
        if(ans==n){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
