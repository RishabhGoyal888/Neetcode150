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

    Node* dfs(map<Node*, Node*> &mp, Node* node){
        if(node == NULL) return NULL;

        if(mp.find(node) != mp.end()) return mp[node];

        Node* copy = new Node(node->val);
        mp[node] = copy;

        for(Node* it: node->neighbors){
            copy->neighbors.push_back(dfs(mp, it));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        return dfs(mp, node);
    }
};