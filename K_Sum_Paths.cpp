//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
    int mod=(int)1e9+7;
    void solve(Node* root,long long int k,long long int prev,long long int &ans,
    unordered_map<long long int,long long int>&map){
        if(!root){
            return;
        }
        long long int current=prev+root->data;
        if(map.find(current-k)!=map.end()){
            ans+=map[current-k]%mod;
        }
        if(current==k){
            ans++;
            ans%mod%mod;
        }
        map[current]++;
        solve(root->left,k,current,ans,map);
        solve(root->right,k,current,ans,map);
        map[current]--;
    }
    int sumK(Node *root,int k)
    {
        if(!root){
            return 0;
        }
        long long int ans=0;
        unordered_map<long long int,long long int> map;
        solve(root,k*1LL,0,ans,map);
        return ans%mod;
    }
};
