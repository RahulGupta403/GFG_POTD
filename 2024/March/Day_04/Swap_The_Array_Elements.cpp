class Solution{
  public:
    void swapElements(int arr[], int n){
        for(int i=0;i<n;i+=1){
            if(i<n and i+2<n){
                swap(arr[i],arr[i+2]);
            }
        }
    }
};
