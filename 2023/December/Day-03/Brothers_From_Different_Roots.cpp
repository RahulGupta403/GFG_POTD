/*
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(),
that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.
*/

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void inorder(Node* root,unordered_map<int,int>&ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans[(root->data)]++;
        inorder(root->right,ans);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,int> ans1,ans2;
        long long int count=0;
        inorder(root1,ans1);
        inorder(root2,ans2);
        for(auto &it: ans1){
            if(ans2[x-it.first]==1){
                count++;
            }
        }
    return count;
    }
};
