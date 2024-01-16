class Solution {
  public:
    void solve(vector<int>&arr,int n,int index,set<vector<int>>&ans){
        if(index==n){
            ans.insert(arr);
            return;
        }
        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            solve(arr,n,index+1,ans);
            swap(arr[index],arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> ans;
        solve(arr,n,0,ans);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
