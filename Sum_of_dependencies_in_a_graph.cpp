#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int v) {
        int count=0;
        for(int i=0;i<v;i++){
            for(auto &it:adj[i]){
                count++;
            }
        }
    return count;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
