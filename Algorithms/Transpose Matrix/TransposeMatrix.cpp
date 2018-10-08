class Solution 
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        int rowLength = A[0].size(), columnLength = A.size();

        for(int i=0; i<rowLength; i++)
        {
            for(int j=0; j<columnLength; j++)
            {
                temp.push_back(0);
            }
            result.push_back(temp);
            temp.clear();
        }
        
        for(int i=0; i<rowLength; i++)
        {
            for(int j=0; j<columnLength; j++)
            {
                result[i][j] = A[j][i];
            }
        }
        return result;
    }
};

