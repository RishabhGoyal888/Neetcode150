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

    Node* dfs(Node* node, map<Node*, Node*> &mp){
        if(node == NULL)
            return NULL;

        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;

        for(Node* n: node->neighbors){
            copyNode->neighbors.push_back(dfs(n,mp));
        }

        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};