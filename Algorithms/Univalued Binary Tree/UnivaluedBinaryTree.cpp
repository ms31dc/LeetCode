/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL)
 *     {
 *     }
 * };
 */

class Solution 
{
public:
    
    void dfs(TreeNode* root, int val, bool &flag)
    {
        if(!root)
        {
            return;
        }
        
        if(root->left)
        {
            if(root->left->val != val)
            {
                flag = false;
            }
        }
        dfs(root->left, val, flag);
        
        if(root->right)
        {
            if(root->right->val != val)
            {
                flag = false;
            }
        }
        dfs(root->right, val, flag);
    }
    
    bool isUnivalTree(TreeNode* root) 
    {
        if(!root)
        {
            return false;
        }
        
        bool flag = true;
        
        dfs(root, root->val, flag);
        
        return flag;
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) 
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) 
    {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) 
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) 
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) 
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) 
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") 
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) 
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") 
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) 
{
    return input ? "True" : "False";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isUnivalTree(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
