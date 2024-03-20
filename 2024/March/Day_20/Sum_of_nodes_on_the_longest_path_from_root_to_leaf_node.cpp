class Solution
{
    void solve(Node *root,int sum,int &maxSum,int len,int &maxlen){
        if(root==NULL){
            if(len>maxlen){
                maxlen=len;
                maxSum=sum;
            }
            else if(len==maxlen){
                maxSum=max(sum,maxSum);
            }
            return;
        }
        sum=sum+root->data;
        solve(root->left,sum,maxSum,len+1,maxlen);
        solve(root->right,sum,maxSum,len+1,maxlen);
    }
public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxSum=0;
        int sum=0;
        int len=0;
        int maxlen=0;
        solve(root,sum,maxSum,len,maxlen);
        return maxSum;
    }
};
