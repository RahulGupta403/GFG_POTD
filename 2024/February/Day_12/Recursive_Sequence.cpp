class Solution{
public:
    #define ll long long int
    #define mod 1000000007
    long long sequence(int n){
        ll sum=0;
        ll till=1;
        for(int i=1;i<=n;i++){
            ll temp=1;
            for(int j=1;j<=i;j++){
                temp=(temp*till)%mod;
                till++;
            }
            sum=(sum+temp)%mod;
        }
    return sum%mod;
    }
};
