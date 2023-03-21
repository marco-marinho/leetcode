/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* current = root;
        while (current){
            current = connectLevel(current);
        }
        return root;
    }

    Node* connectLevel(Node* node){
        Node* first = nullptr;
        while(node && !first){
            if(node->left) first = node->left;
            else if (node->right) first = node->right;
            else node = node->next;
        }
        if (!first) return nullptr;
        Node* prev = first;
        while(node){
            if (node->left && node->left != prev) {
                prev->next = node->left;
                prev = node->left;
            }
            if (node->right && node->right != prev){
                prev->next = node->right;
                prev = node->right;
            }
            node = node->next;
        }
        if (prev) prev->next = nullptr;
        return first;
    }

};