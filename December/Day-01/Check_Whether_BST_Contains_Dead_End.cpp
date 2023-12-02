/*
The Node structure is
struct Node {
int data;
Node * right, * left;
};
*/
class Solution{
  public:
    bool solve(Node* root,int min,int max){
        if(!root){
            return false;
        }
        if(min==max){
            return true;
        }
        bool ans1=solve(root->left,min,root->data-1);
        bool ans2=solve(root->right,root->data+1,max);
        return ans1 or ans2;
    }
    bool isDeadEnd(Node *root)
    {
        return solve(root,1,INT_MAX);
    }
};
