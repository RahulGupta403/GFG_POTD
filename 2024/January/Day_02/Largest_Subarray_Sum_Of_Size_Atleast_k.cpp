class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
    long long int ans=INT_MIN;
    long long int curr_sum=0;
    long long int front_sum=0;
    long long int front_pointer=0;
    long long int curr_pointer=0;
    while(curr_pointer<k){
        curr_sum+=a[curr_pointer];
        curr_pointer++;
    }
    ans=curr_sum;
    while(curr_pointer<n){
        curr_sum+=a[curr_pointer];
        curr_pointer++;
        front_sum+=a[front_pointer];
        front_pointer++;
        if(front_sum<0){
            curr_sum-=front_sum;
            front_sum=0;
        }
        ans=max(ans,curr_sum);
    }
    return ans; 
    }
};
