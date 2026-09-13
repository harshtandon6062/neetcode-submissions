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
    unordered_map<Node*, Node*> clone_map;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node * clone = new Node(node->val);
        clone_map[node] = clone;
        for(Node *nei: node->neighbors){
            if(!clone_map.count(nei)) cloneGraph(nei);
            clone->neighbors.push_back(clone_map[nei]);
        }
        return clone;
    }
};
