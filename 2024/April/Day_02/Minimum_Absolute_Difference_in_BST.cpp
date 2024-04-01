//Initial Approach 
//---Verdict Accepted
class Solution
{
    public:
    void inorder(Node* root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans,cnt);
        ans.push_back(root->data);
        inorder(root->right,ans,cnt);
    }
    int absolute_diff(Node *root)
    {
        if(!root) return 0;
        vector<int>ans;
        int cnt=INT_MAX;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
          cnt=min(cnt,abs(ans[i+1]-ans[i]));
        }
        return cnt;
    }
};

// Optimal Approach
// ---Verdict Accepted
class Solution
{
    public:
    void inorder(Node* root,int &ans,int &cnt){
        if(!root) return;
        inorder(root->left,ans,cnt);
        ans=min(ans,abs(cnt-root->data));
        cnt=root->data;
        inorder(root->right,ans,cnt);
    }
    int absolute_diff(Node *root)
    {
        if(!root) return 0;
        int ans=INT_MAX;
        int cnt=INT_MAX;
        inorder(root,ans,cnt);
        return ans;
    }
};
