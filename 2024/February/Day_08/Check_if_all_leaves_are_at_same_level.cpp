class Solution{
  public:
    /*You are required to complete this method*/
    int minDistance(Node* root){
        if(root==NULL) return INT_MAX;
        if(root->left==NULL and root->right==NULL) return 1;
        int left=minDistance(root->left);
        int right=minDistance(root->right);
        return 1+min(left,right);
    }
    int maxDistance(Node* root){
        if(!root) return 0;
        int left=maxDistance(root->left);
        int right=maxDistance(root->right);
        return 1+max(left,right);
    }
    bool check(Node *root)
    {
        int minDist=minDistance(root);
        int maxDist=maxDistance(root);
        return minDist==maxDist;
    }
};
