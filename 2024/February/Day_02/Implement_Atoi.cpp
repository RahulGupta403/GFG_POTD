class Solution{
  public:
    /*You are required to complete this method */
    #define ll long long int
    int atoi(string s) {
        ll ans=0;
        ll sign=1;
        for(int i=0;i<s.size();i++){
            if(i==0 and s[i]=='-'){
                sign=-1;
            }
            else if(s[i]>='0' and s[i]<='9'){
                int digit=s[i]-'0';
                ans=ans*10+digit;
            }else{
                return -1;
            }
        }
    return ans*sign*1LL;
    }
};
