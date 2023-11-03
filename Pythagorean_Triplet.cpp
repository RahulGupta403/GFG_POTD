//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    sort(arr,arr+n);
	    for(int i=n-1;i>0;i--){
	        int ans=arr[i]*arr[i];
	        int end=i-1;
	        int start=0;
	        while(start<end){
	            if(ans==(arr[end]*arr[end]+arr[start]*arr[start])){
	                return true;
	            }else if(ans>(arr[end]*arr[end]+arr[start]*arr[start])){
	                start++;
	            }else if(ans<(arr[end]*arr[end]+arr[start]*arr[start])){
	                end--;
	            }
	        }
	    }
	return false;
	}
};
