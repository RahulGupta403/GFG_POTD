//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    bool dfs(int n,int k,int total_possibilities,string &path,
    set<string>&visited){
        if(visited.size()==total_possibilities){
            return  true;
        }
        for(int i=0;i<k;i++){
            string curr_node=path.substr(path.size()-n+1);
            curr_node.push_back('0'+i);
            if(visited.find(curr_node)==visited.end()){
                visited.insert(curr_node);
                path.push_back('0'+i);
                if(dfs(n,k,total_possibilities,path,visited)==true){
                    return true;
                }
                path.pop_back();
                visited.erase(curr_node);
            }
        }
        return false;
    }
    string findString(int n, int k) {
        string path=string(n-1,'0');
        set<string> visited;
        int total_possibilities=pow(k,n);
        dfs(n,k,total_possibilities,path,visited);
        return path;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends
