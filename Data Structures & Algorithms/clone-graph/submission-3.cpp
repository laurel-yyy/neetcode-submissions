/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp; //origin -> clone
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        if(mp[node] != NULL) return mp[node];
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto neighbor : node->neighbors){
            Node* cloneneighbor = cloneGraph(neighbor);
            clone->neighbors.push_back(cloneneighbor);
        }
        return clone;
    }
};
