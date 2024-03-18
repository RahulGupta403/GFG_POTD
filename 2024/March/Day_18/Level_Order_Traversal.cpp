class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        Node* temp=root;
        queue<Node*> q;
        q.push(temp);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                ans.push_back(front->data);
            }
        }
    return ans;
    }
};
