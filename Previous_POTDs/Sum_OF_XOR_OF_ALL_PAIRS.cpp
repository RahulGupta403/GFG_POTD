//Brute Force Approach O(n^2)
class Solution{
    public:
    long long int sumXOR(int arr[], int n)
    {
        long long int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum+=(arr[i]^arr[j]);
            }
        }
        return sum;
    }
};


// Optimised Code O(n)
class Solution{
  public:
  long long int sumXOR(int arr[], int n)
  {
      long long int sum=0;
      for(int i=0;i<32;i++){
          long long int oneSetBits=0;
          long long int zeroSetBits=0;
          for(int j=0;j<n;j++){
              if((arr[j]&(1<<i))){
                  oneSetBits++;
              }else{
                  zeroSetBits++;
              }
          }
          sum+=(oneSetBits*1LL*zeroSetBits*(1<<i));
      }
      return sum;
  }
};
