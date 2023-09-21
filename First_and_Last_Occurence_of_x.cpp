#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int left_Occurence(int *arr,int n,int x){
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x){
                ans=mid;
                high=mid-1;
            }else if(arr[mid]<x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int right_Occurence(int *arr,int n,int x){
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x){
                ans=mid;
                low=mid+1;
            }else if(arr[mid]<x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        int left=left_Occurence(arr,n,x);
        if(left==-1){
            return {-1,-1};
        }
        int right=right_Occurence(arr,n,x);
        return {left,right};
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
