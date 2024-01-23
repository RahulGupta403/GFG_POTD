#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int isRepresentingBST(int arr[], int n)
    {
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                return false;
            }
        }
    return true;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}
