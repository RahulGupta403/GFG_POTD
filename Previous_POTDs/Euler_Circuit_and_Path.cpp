#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    int odd=0;
        for(int i =0;i<V ;i++){
           if(adj[i].size()&1){
               odd++;
           } 
        }
        if(odd>2)  return 0;
        if(odd==2){
            return 1;
        }else{
            return 2;
        }
	}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
