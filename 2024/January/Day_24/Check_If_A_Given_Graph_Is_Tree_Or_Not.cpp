// Simple Approach maintain an adjacency list and do Depth FIrst Travesal and check if all nodes are visited or not.:-)
class Solution {
public:
    void dfs(vector<int>adj[],int node,vector<int>&visited){
        visited[node]=1;
        for(auto &it:adj[node]){
            if(!visited[it]){
                dfs(adj,it,visited);
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &edges) {
        if((n-m)!=1){
            return 0;
        }
        vector<int> adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        dfs(adj,0,visited);
        for(auto &it:visited){
            if(it==0){
                return 0;
            }
        }
    return 1;
    }
};
