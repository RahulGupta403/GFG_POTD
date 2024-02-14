class Solution {
public:
	 struct DSU{
        int n;
        vector<int>par;
        
        DSU(int n)
        {
            par.clear();par.resize(n);
            
            for(int i=0;i<n;i++) par[i]=i;
        }
        
        int find(int node)
        {
            if(par[node]==node) return node;
            return par[node] = find(par[node]);
        }
        
        void unite(int a, int b)
        {
            a = find(a);
            b = find(b);
            
            if(a==b) return;
            par[a] = b;
        }
    };
    vector<int>col;
    vector<int>par;
    void dfs(int node, int p, vector<int>&s, vector<int> g[], DSU& a)
    {
        col[node]=1;
        s.push_back(node);
        if(p!=-1) par[node] = p;
        for(auto c:g[node])
        {
            if(col[c]==0)
            {
                dfs(c,node,s,g,a);
            }
            else if(col[c]==1)
            {
                if(c!=p)
                {
                    int i = s.size()-1;
                    int x = c;
                    while(i>=0 && s[i]!=c)
                    {
                        a.unite(x,s[i]);
                        x = s[i];i--;
                    }
                }
            }
        }
        col[node]=2;
        s.pop_back();
    }
	vector<vector<int>>criticalConnections(int n, vector<int> g[]){
	    col.clear();col.resize(n);
	    par.clear();par.resize(n);
	    DSU a(n);
	    set<vector<int>>s;
	    vector<vector<int>>ans;
	    vector<int>v;
	    dfs(0,-1,v, g,a);
	    for(int i=0;i<n;i++)
	    {
	        for(auto c:g[i])
	        {
	            if(a.find(c)!=a.find(i))
	            {
	               s.insert({min(i,c),max(i,c)});
	            }
	        }
	    }
	    for(auto v:s)
	    {
	        ans.push_back(v);
	    }
	    return ans;
	}
};
