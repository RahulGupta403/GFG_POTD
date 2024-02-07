class Solution{
   public:
   /* Should return minimum distance between a and b
   in a tree with given root*/
   
   Node* LCA(Node *root,int a,int b){
       if(root==NULL)
           return NULL;
       if(root->data==a or root->data==b)
           return root;
           
       Node *left=LCA(root->left,a,b);
       Node *right=LCA(root->right,a,b);
       
       if(left!=NULL and right!=NULL)
           return root;
       else if(left!=NULL)
           return left;
       else 
           return right;
   }
   int match_value(Node *root,int x,int d){
       if(root==NULL)
           return INT_MAX;
       
       if(root->data==x)
           return d;
       int p=match_value(root->left,x,d+1);
       int q=match_value(root->right,x,d+1);
       return min(p,q);
   }
   
   int findDist(Node* root, int a, int b) {
       Node *lca=LCA(root,a,b);
       int left=match_value(lca,a,0);
       int right=match_value(lca,b,0);
       return left+right;
   }
};
