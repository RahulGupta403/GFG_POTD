class Solution {
  public:
    void help(Node* root,int n,int &ans){
        if(!root) return;
        
        if(root->key<=n){
            ans=root->key;
            help(root->right,n,ans);
        }
        else{
            help(root->left,n,ans);
        }
        
    }
    int findMaxForN(Node* root, int n) {
        // code here
        int ans=-1;
        help(root,n,ans);
        return ans;
    }
};
