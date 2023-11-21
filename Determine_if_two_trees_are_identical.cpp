class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL and r2!=NULL){
            return false;
        }
        if(r1!=NULL and r2==NULL){
            return false;
        }
        if(r1==NULL and r2==NULL){
            return true;
        }
        bool ans1=isIdentical(r1->left,r2->left);
        bool ans2=isIdentical(r1->right,r2->right);
        if(ans1 and ans2 and r1->data==r2->data){
            return true;
        }else{
            return false;
        }
    }
};
