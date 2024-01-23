#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        int minima,maxima;
        for(int i=0;i<n-1;i++){
            minima=min(smallest,arr[i+1]-k);
            maxima=max(largest,arr[i]+k);
            if(minima<0){
                continue;
            }
            ans=min(ans,maxima-minima);
        }
    return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
