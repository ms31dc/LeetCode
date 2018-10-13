class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> output;
        vector<vector<int>> result = matrix;
        for(int i = 0; i<matrix.size();i++)
        {
            for(int j = 0; j<matrix[0].size();j++)
            {
                result[i][j] = 1;
            }
        }
        
        int i=0,j=0;
        if(matrix.size() > 0)
        {
            while(true)
            {
                output.push_back(matrix[i][j]);
                result[i][j] = 0;
                
                if(i-1 >= 0 && result[i-1][j] == 1 && (j-1 < 0 || result[i-1][j-1] == 0))
                {
                    i--;   
                }
                else if(j+1 < result[0].size() && result[i][j+1] == 1)
                {
                    j++;
                }
                else if(i+1 < result.size() && result[i+1][j] == 1)
                {
                    i++;
                }
                else if(j-1 >= 0 && result[i][j-1] == 1)
                {
                    j--;
                }
                else if(i-1 >= 0 && result[i-1][j] == 1)
                {
                    i--;
                }
                else
                {
                    break;
                }
            }
        }
        return output;
    }
};
