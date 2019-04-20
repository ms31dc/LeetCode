/*
// Definition for a Node.
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node()
    {
    }

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
    void postOrderTraversal(Node* root, vector<int>& result)
    {
        if(!root)
        {
            return;
        }
        
        int childrenSize = root->children.size();
        
        for(int i=0; i<childrenSize; i++)
        {
            postOrderTraversal(root->children[i], result);
        }
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root)
    {
        vector<int> result;
        postOrderTraversal(root, result);
        return result;
    }
};
