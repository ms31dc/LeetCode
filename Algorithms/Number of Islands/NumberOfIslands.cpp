class Solution
{
public:
    void fillNeighborWithZero(vector<vector<char>>& grid, int row, int column)
    {
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == '0')
        {
            return;
        }
        
        if(grid[row][column] == '1')
        {
            grid[row][column] = '0';
        }
        
        fillNeighborWithZero(grid, row-1, column); //UP
        fillNeighborWithZero(grid, row+1, column); //DOWN
        fillNeighborWithZero(grid, row, column+1); //RIGHT
        fillNeighborWithZero(grid, row, column-1); //LEFT
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    result++;
                    fillNeighborWithZero(grid, i, j);
                }
            }
        }
        return result;
    }
};
