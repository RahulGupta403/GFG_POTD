//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int solveSpace(long long arr[],int n){
        if(n==1){
            return 1;
        }
        long long int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        long long int sumneeded=0;
        for(int i=0;i<n;i++){
            sumneeded+=arr[i];
            if(sumneeded==totalsum){
                return i+1;
            }
            totalsum-=arr[i];
        }
        return -1;
    }
    int equilibriumPoint(long long arr[], int n) {
        // My First Appraoch much its a bit spacious time for better approach let's go for that.
        // long long prefixsum[n]={0};
        // prefixsum[0]=arr[0];
        // for(int i=1;i<n;i++){
        //     prefixsum[i]=prefixsum[i-1]+arr[i];
        // }
        // long long suffixsum[n]={0};
        // suffixsum[n-1]=arr[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suffixsum[i]=suffixsum[i+1]+arr[i];
        // }
        // for(int i=0;i<n;i++){
        //     if(prefixsum[i]==suffixsum[i]){
        //         return i+1;
        //     }
        // }
        // return -1;
        
        return solveSpace(arr,n);
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
