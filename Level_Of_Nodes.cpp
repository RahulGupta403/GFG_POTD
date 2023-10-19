class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        //{node,distance} pair
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dist = it.second;
            vis[node] = 1;
            //if the node has been reached then return the distance(level)
            if(node==X)return dist;
            for(auto itr:adj[node]){
                if(!vis[itr]){
                    q.push({itr,dist+1});
                }
            }
        }
    return -1;
	}
};
