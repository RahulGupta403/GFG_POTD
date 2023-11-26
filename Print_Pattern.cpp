class Solution{
    private:
    void Util(vector<int>&ans,int N,int key){
        //base case
        if(N==key){
            ans.push_back(N);
            return;
        }
        ans.push_back(N);
        Util(ans,N+5,key);
    }
    void solve(vector<int>&ans,int N,int key){
        //base case
        if(N<=0){
            Util(ans,N,key);
            return;
        }
        ans.push_back(N);
        solve(ans,N-5,key);
    }  
public:
    vector<int> pattern(int N){
        vector<int>ans;
        int key=N;
        solve(ans,N,key);
        return ans;
    }  
};
