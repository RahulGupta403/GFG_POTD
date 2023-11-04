class Solution
{
public:
    int transitionPoint(int arr[], int n) {
        int low=0;
        int end=n-1;
        int ans=-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(arr[mid]==1){
                ans=mid;
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return ans;
    }
};
