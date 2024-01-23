//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n,int k,vector<int>&arr1,vector<int>&arr2){
        sort(arr1.begin(),arr1.end(),greater<int>());
        sort(arr2.begin(),arr2.end(),greater<int>());
        priority_queue<pair<int,int>> maxheap;
        vector<int> ans;
        for(int i=0;i<n;i++){
            maxheap.push({(arr1[0]+arr2[i]),0});
        }
        while(k--){
            auto x=maxheap.top();
            int i=x.first;
            int j=x.second;
            maxheap.pop();
            ans.push_back(i);
            
            maxheap.push({i-arr1[j]+arr1[j+1],j+1});
        }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
