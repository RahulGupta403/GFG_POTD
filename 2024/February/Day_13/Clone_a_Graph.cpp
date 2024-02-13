//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* vis[10001] = {NULL};
    Node* cloneGraph(Node* node) {
    Node* graph = new Node(node->val);
    vis[node->val] = graph;
    for(auto it: node->neighbors){
        if(!vis[it->val]) cloneGraph(it);
        graph->neighbors.push_back(vis[it->val]);
    }
    return graph;
}
};
