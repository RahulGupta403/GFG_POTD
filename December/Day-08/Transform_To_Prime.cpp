class Solution
{
    public:
    #define ll long long int 
    bool isPrime(ll sum){
        if(sum<2){
            return false;
        }
        for(int i=2;i*i<=sum;i++){
            if(sum%i==0){
                return false;
            }
        }
        return true;
    }
    ll nextPrime(ll sum){
        while(true){
            if(isPrime(sum)){
                return sum;
            }else{
                sum++;
            }
        }
    }
    int minNumber(int arr[],int n)
    {
        ll sum=accumulate(arr,arr+n,0);
        if(isPrime(sum)){
            return 0;
        }else{
            return nextPrime(sum)-sum;
        }
    }
};
