class Solution 
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        vector<int> rowHighest, columnHighest;
        int highestValue = 0;
        int result = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] > highestValue)
                {
                    highestValue = grid[i][j];
                }
            }            
            rowHighest.push_back(highestValue);
            highestValue = 0;            
        }
        
        for(int i=0; i<grid[0].size(); i++)
        {
            for(int j=0; j<grid.size(); j++)
            {
                if(grid[j][i] > highestValue)
                {
                    highestValue = grid[j][i];
                }
            }
            columnHighest.push_back(highestValue);
            highestValue = 0;            
        }
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(rowHighest[i] < columnHighest[j])
                {
                    result = result + (rowHighest[i] - grid[i][j]);
                }
                else
                {
                    result = result + (columnHighest[j] - grid[i][j]);
                }
            }
        }
        return result;
    }
};

