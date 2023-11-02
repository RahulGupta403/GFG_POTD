class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
       int ans = INT_MAX,a = -1,b = -1;
       for(int i=0; i<n; i++)
       {
           if(arr[i] == x)
               a=i;
           if(arr[i] == y)
               b=i;
           if(a!=-1 && b!=-1)
               ans = min(ans,abs(a-b));
       }
       
       if(ans == INT_MAX || ans == 0)
           return -1;
       else
           return ans;
    }
};
