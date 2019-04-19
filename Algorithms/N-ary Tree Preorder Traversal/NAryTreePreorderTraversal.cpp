/*
// Definition for a Node.
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    }
};

*/
class Solution 
{
public:
    void preOrderTraversal(Node* root, vector<int>& result)
    {
        if(!root)
        {
            return;
        }
        
        result.push_back(root->val);
        int childrenSize = root->children.size();
        
        for(int i=0; i<childrenSize; i++)
        {
            preOrderTraversal(root->children[i], result);
        }
    }
    
    vector<int> preorder(Node* root) 
    {
        vector<int> result;
        preOrderTraversal(root, result);
        return result;
    }
};
