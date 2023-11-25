#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	void shuffleArray(int a[],int n){
        int maxval = 1e4;
        for(int i=2, j=1; i<n; i+=2, j++) 
            a[i] = (a[j] % maxval) * maxval + a[i];
        for(int i=1, j=n/2; i<n; i+=2, j++)
            a[i] = (a[j] % maxval) * maxval + a[i];
        for(int i=1;i<n;i++)
            a[i] = a[i] / maxval;
    }
};
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
        Solution ob;
        ob.shuffleArray(a, n);
		    for (int i = 0; i < n; i++) 
			  cout << a[i] << " ";
	      cout << "\n";
    }
    return 0;
}
