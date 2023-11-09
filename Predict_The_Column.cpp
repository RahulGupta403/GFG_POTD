class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int n){
        int index=-1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[j][i]==0){
                    count++;
                }
            }
            if(count>0 and count>maxi){
                maxi=count;
                index=i;
            }
        }
        return index;
    }
};
