class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upper=0;
        int lower=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<=j){
                    upper+=matrix[i][j];
                }
                if(i>=j){
                    lower+=matrix[i][j];
                }
            }
        }
    return {upper,lower};
    }
};
