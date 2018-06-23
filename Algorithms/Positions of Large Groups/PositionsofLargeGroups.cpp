class Solution 
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        int i, index = 0, count = 1, startLocation = 0;
        char ch = S[0];
        vector<vector<int>> result;
        for(i=1; i<S.length(); i++)
        {
            if(S[i] == ch)
            {
                count++;
            }
            else
            {
                if(count >= 3)
                {
                    vector<int> temp;
                    temp.push_back(startLocation);
                    temp.push_back(i-1);
                    result.push_back(temp);
                }
                count = 1;
                ch = S[i];
                startLocation = i;
            }
        }
        if(count >= 3)
        {
            vector<int> temp;
            temp.push_back(startLocation);
            temp.push_back(i-1);
            result.push_back(temp);
        }
        return result;
    }
};
