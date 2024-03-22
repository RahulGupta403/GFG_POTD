class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                while(front){
                    sum+=front->data;
                    if(front->left){
                        q.push(front->left);
                    }
                    front=front->right;
                }
            }
            ans.push_back(sum);
        }
    return ans;
    }
};
