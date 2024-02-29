class Solution{
public:
    #define ll long long int 
	long long sumBitDifferences(int arr[], int n) {
	   ll ans = 0;
	   for(int i = 0;i<32;i++){
	       ll count = 0;
	       for(int j = 0;j<n;j++){
	           // at each position find the set bit
	           if(arr[j]&(1<<i)){
	               count++;
	           }
	       }
	       ans+=count*(n-count)*2;
	   }
	   return ans;
	}
};
