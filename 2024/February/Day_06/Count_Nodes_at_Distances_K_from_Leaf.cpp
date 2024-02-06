//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    void helperFun(Node *root , int k , unordered_map<int , bool>&vis , int level , int &ans){
        if(!root){
            return;
        }
        vis[level] = false;
        if(!root->left and !root->right and level- k >= 0 and vis[level - k] == false){
            vis[level - k] = true;
            ans++;
            return;
        }
        helperFun(root->left , k , vis , level + 1 , ans);
        helperFun(root->right , k , vis , level + 1 , ans);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
        unordered_map<int , bool>mp;
        int ans = 0;
        helperFun(root , k , mp , 0 , ans);
        return ans;
    }
};
