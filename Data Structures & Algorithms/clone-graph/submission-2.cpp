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
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> visited;
        
        queue<Node*> q;
        Node* rootClone = new Node(node->val);
        visited[node] = rootClone;
        
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                
                if (visited.find(neighbor) == visited.end()) {
                    // 1. Clone the neighbor
                    visited[neighbor] = new Node(neighbor->val);
                    // 2. Push original neighbor to queue so we can process its connections later
                    q.push(neighbor);
                }

                // Connect the cloned current node to the cloned neighbor node
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        return rootClone;
    }
};
