class Solution{
    public:
    #define ll long long int 
    long countSubarrays(int arr[], int n, int L, int R)
    {
        ll ans=0;
        ll i=0;
        ll j=0;
        ll count=0;
        while(j<n){
            if(arr[j]>=L and arr[j]<=R){
                count=j-i+1;
            }
            else if(arr[j]>R){
                count=0;
                i=j+1;
            }
            j++;
            ans+=count;
        }
        return ans;
    }
};
