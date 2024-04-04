class Solution
{
    public:
    #define mod 1000000007
    #define ll long long int
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        ll ans=0;
        ll n=s.size();
        ll total=s[0]-'0';
        ll currsum=s[0]-'0';
        ll j=2;
        for(int i=1;i<n;i++){
            currsum=((s[i]-'0')*j)%mod+(10*currsum)%mod;
            total=(total%mod+currsum%mod)%mod;
            j++;
        }
    return total%mod;
    }
};


/*
s="1234"
1 ===> 10*0+1*1;
12 2 =====> (2*2+10*prevsum)---->prevsum
123 23 3 ======> 120 20 3*3 -----> (s[i]-'0')*j+10*prevsum
1234 234 34 4
*/

