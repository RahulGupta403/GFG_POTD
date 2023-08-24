//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1},{-1,-1},
    {-1,1},{1,-1},{1,1}};
    bool possible(vector<vector<char>>grid, string word,int i,int j){
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    for(auto dir:dirs){
	        int new_x=i;
	        int new_y=j;
	        int count=0;
	        while(new_x>=0 and new_x<n and new_y>=0 and new_y<m && 
	        count<word.length() and grid[new_x][new_y]==word[count]){
	            new_x+=dir[0];
	            new_y+=dir[1];
	            count++;
	        }
	        if(count==word.length()){
	            return true;
	        }
	    }
	return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0] && possible(grid,word,i,j)){
	                ans.push_back({i,j});
	            }
	        }
	    }
	 return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends