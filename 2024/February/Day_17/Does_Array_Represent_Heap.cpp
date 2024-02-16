class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            if((2*i+1<n and arr[i]<arr[2*i+1]) or 
            (2*i+2<n and arr[i]<arr[2*i+2])){
                return false;
            }
        }
        return true;
    }
};