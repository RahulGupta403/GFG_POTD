class Solution{
    public:
    int firstElementKTime(int n, int k, int arr[])
    {
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
            if(map[arr[i]]==k){
                return arr[i];
            }
        }
    return -1;
    }
};
