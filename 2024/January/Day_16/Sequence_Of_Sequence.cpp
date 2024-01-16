class Solution{
public:
      int f(int m, int n, int len, int num){
        if(len==n){
           return 1;
        }
        if(num>m) return 0;
        // pick or not Pick
        int notPick = f(m,n,len,num+1);
        int pick = f(m,n,len+1,num*2); 
        return notPick + pick;
    }
    int numberSequence(int m, int n){
        return f(m,n,0,1);
    }
};
