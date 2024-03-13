class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n=mat.size();
        map<int,vector<int>> map;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[abs(i+j)].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto it:map){
            if(it.first%2==0){
                for(int i=it.second.size()-1;i>=0;i--){
                    ans.push_back(it.second[i]);
                }
            }else{
                for(int i=0;i<=it.second.size()-1;i++){
                    ans.push_back(it.second[i]);
                }
            }
        }
    return ans;
    }
};
