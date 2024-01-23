class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetricHelp(struct Node* root1,struct Node* root2)
    {
        if(root1==NULL and root2==NULL){
            return true;
        }
        if(root1!=NULL and root2==NULL){
            return false;
        }
        if(root1==NULL and root2!=NULL){
            return false;
        }
        bool leftans=isSymmetricHelp(root1->left,root2->right);
        bool rightans=isSymmetricHelp(root1->right,root2->left);
        bool value=root1->data==root2->data;
        if(leftans and rightans and value){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSymmetric(struct Node* root){
        return isSymmetricHelp(root,root);
    }
};
