/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        Stack<Node> queue = new Stack<>();
        queue.push(root);
        List<Integer> output = new ArrayList<>();
        while(!queue.isEmpty()){
            Node temp = queue.pop();
            if (temp == null){
                continue;
            }
            output.add(temp.val);
            for(int idx = temp.children.size()-1; idx >= 0; idx--){
                Node child = temp.children.get(idx);
                queue.push(child);
            }
        }
        return output;
    }
}