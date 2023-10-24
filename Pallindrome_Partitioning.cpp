#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //Cache memory for fast response
    int t[501][501]; 
    // Just a normal function for checking palindrome
    bool isPalin(string &s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int helper(string &s, int i, int j){
        // If there are no elements, then no partition needed.
        if(i >= j) return 0; 
        // If subproblem is already calculated, then that from there
        if(t[i][j] != -1) return t[i][j]; 
        // If already is a palindrome, then no need to partitioning.
        if(isPalin(s, i, j)) return 0; 
        // Mini variable for calculating, the minimum value
        int mini = INT_MAX; 
        // Checking for all possibilities of partitioning, like - MCM
        for(int k=i;k<=j-1;k++){
            // increament by '1', for the track the no. of partition
            int left = 0, right = 0;
            if(t[i][k] != -1) left = t[i][k];
            else{
                left = helper(s, i, k);
                t[i][k] = left;
            }
            if(t[k+1][j] != -1) right = t[k+1][j];
            else{
                right = helper(s, k+1, j);
                t[k+1][j] = right;
            }
            int ans = 1 + left + right;
            // Update Minimum Variable
            mini = min(mini, ans);
        }
        // Store and return our answer
        return t[i][j] = mini; 
    }
    int palindromicPartition(string str){
        //Initialize cache memory with all '-1'
        memset(t, -1, sizeof(t)); 
        return helper(str, 0, str.size()-1);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
