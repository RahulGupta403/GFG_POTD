class Solution
{
    public:
    /*You are required to complete below method */
    int sum;
    void inorder(Node* root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(root and root->left==NULL and root->right==NULL){
            sum+=root->data;
        }
        inorder(root->right);
    }
    int sumOfLeafNodes(Node *root ){
         sum=0;
         inorder(root);
    return sum;
    }
};
