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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> nodes;
        set<int> visited;
        stack<Node*> toVisit;
        toVisit.push(node);
        while(!toVisit.empty()){
            auto curr = toVisit.top();
            toVisit.pop();
            if(visited.count(curr->val)) continue;
            visited.insert(curr->val);
            nodes[curr->val] = new Node(curr->val);
            for (auto n : curr->neighbors){
                toVisit.push(n);
            }
        }
        visited.clear();
        toVisit.push(node);
        while(!toVisit.empty()){
            auto curr = toVisit.top();
            toVisit.pop();
            if(visited.count(curr->val)) continue;
            visited.insert(curr->val);
            for (auto n : curr->neighbors){
                nodes[curr->val]->neighbors.emplace_back(nodes[n->val]);
                toVisit.push(n);
            }
        }
        return nodes[1];
    }
};
