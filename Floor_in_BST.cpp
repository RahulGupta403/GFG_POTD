// Approach-01 (Naive Approach)
// ACCEPTED SOLUTION
// Function to search a node in BST.
class Solution{
public:
    void inorder(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int floor(Node* root, int x) {
        vector<int> ans;
        inorder(root,ans);
        int lb=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==x){
                return x;
            }
            else if(ans[i]<x){
                lb=max(lb,ans[i]);
            }
        }
        return lb;
    }
};






// Approach-02(OPTIMAL APPROACH)
// Function to search a node in BST.
class Solution{

public:
    int ans;
    void inorder(Node* root,int x){
        if(root==NULL){
            return;
        }
        inorder(root->left,x);
        if(root->data<=x){
            ans=root->data;
        }else{
            return;
        }
        inorder(root->right,x);
    }
    int floor(Node* root, int x) {
        // Code here
        ans=-1;
        inorder(root,x);
        return ans;
    }
};

