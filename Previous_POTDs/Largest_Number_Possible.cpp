//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int nums, int sum){
        string ans="";
        if(sum==0 and nums==1){
            return "0";
        }
        if(sum==0 and nums>1){
            return "-1";
        }
        for(int i=0;i<nums;i++){
            if(sum>=9){
                ans+=to_string(9);
                sum-=9;
            }else{
                ans+=to_string(sum);
                sum=0;
            }
        }
        if(sum>0){
            return "-1";
        }
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
