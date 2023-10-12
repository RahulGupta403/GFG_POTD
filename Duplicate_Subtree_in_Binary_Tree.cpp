/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string, int>mp;
    string getSubstring(Node* root){
        if(!root) return "$";
        string s="";
        if(!root->right and !root->left){
            s+=to_string(root->data);
            return s;
        }
        s+=to_string(root->data);
        s+='/';
        s+=getSubstring(root->left);
        s+=getSubstring(root->right);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
        getSubstring(root);
        for(auto it:mp)
        if(it.second>=2) return true;
        return false;
    }
};
