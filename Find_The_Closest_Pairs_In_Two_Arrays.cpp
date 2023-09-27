//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans;
        int i=0;
        int j=m-1;
        int closest_diff=INT_MAX;
        int element1,element2;
        while(i<n and j>=0){
            int sum=arr[i]+brr[j];
            if(abs(x-sum)<closest_diff){
                closest_diff=abs(x-sum);
                element1=arr[i];
                element2=brr[j];
            }
            if(sum>x){
                j--;
            }else{
                i++;
            }
        }
    return {element1,element2};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
