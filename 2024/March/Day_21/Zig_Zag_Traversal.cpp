class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool dir=true;
        while(q.size()){
            int size=q.size();
            vector<int>res;
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                res.push_back(front->data);
            }
            if(dir){
                for(auto &it: res){
                    ans.push_back(it);
                }
                dir=!dir;
            }
            else if(!dir){
                reverse(res.begin(),res.end());
                for(auto &it: res){
                    ans.push_back(it);
                }
                dir=!dir;
            }
            
        }
    return ans;
    }
}:
