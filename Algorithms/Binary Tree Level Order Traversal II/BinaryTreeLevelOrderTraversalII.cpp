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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        if(root)
        {
            queue<TreeNode*> Q;
            Q.push(root);
            
            while(!Q.empty())
            {
                int length = Q.size();
                vector<int> temp;
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
            reverse(result.begin(), result.end());
        }
        return result;
    }
};
