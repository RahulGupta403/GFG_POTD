class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int row, int col) 
    { 
        map<vector<int>,int>map;
        vector<int> res;
        for(int i=0;i<row;i++){
            vector<int> ans;
            for(int j=0;j<col;j++){
                ans.push_back(matrix[i][j]);
            }
            if(map.find(ans)==map.end()){
                map[ans]=i+1;
            }else{
                res.push_back(i);
                map[ans]=i+1;
            }
        }
    return res;
    } 
};
