// This is not the optimal approach for this question although this is also an accepted solution!!!

// (Learning the best approach(Dgit DP) and update it asap)
class Solution {
   public:
    #define ll long long int 
    ll digit(ll num,ll match){
         ll count=0;
         while(num>0){
             ll dig=num%10;
             if(dig==match){
                 count++;
             }
             num/=10;
         }
    return count;
    }
    int countX(int L, int R, int X) {
        ll ans=0;
        L++;
        while(L<R){
            ans+=digit(L,X);
            L++;
        }
    return 1LL*ans;
    }
};
