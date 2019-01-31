/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        
        if(root != NULL)
        {
            queue<TreeNode*> Q;
            Q.push(root);
            while(!Q.empty())
            {
                vector<int> temp;
                int length = Q.size();
                for(int i=0; i<length; i++)
                {
                    TreeNode* current = Q.front();
                    temp.push_back(current->val);
                    if(current->left != NULL)
                    {
                        Q.push(current->left); 
                    }
                    if(current->right != NULL)
                    {
                        Q.push(current->right); 
                    }
                    Q.pop();                    
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};
