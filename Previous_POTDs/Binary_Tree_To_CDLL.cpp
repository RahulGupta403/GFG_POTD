class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *prev = nullptr, *head = nullptr;
    void inorder(Node *root) {
        if(!root) return;
        inorder(root->left);
        if(!head) head = prev = root;
        else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }
    public:
    Node *bTreeToCList(Node *root) {
        inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};
