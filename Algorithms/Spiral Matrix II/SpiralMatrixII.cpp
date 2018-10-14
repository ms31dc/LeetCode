class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result;
        vector<int> temp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp.push_back(0);
            }
            result.push_back(temp);
            temp.clear();
        }
        
        int i=0, j=0, value=1;
        
        if(n > 0)
        {
            while(true)
            {
                result[i][j] = value;
                value++;
                
                if(i-1 >= 0 && result[i-1][j] == 0 && (j-1 < 0 || result[i-1][j-1] != 0))
                {
                    i--;
                }
                else if(j+1 < result[0].size() && result[i][j+1] == 0)
                {   
                    j++;
                }
                else if(i+1 < result.size() && result[i+1][j] == 0)
                {
                    i++;
                }
                else if(j-1 >= 0 && result[i][j-1] == 0)
                {
                    j--;
                }
                else if(i-1 >= 0 && result[i-1][j] == 0)
                {
                    i--;
                }
                else
                {
                    break;
                }
            }
        }
        return result;
    }
};
