class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> index;
        vector<int> result;
        int smallestDistance=0;
        for(int i=0; i<S.length(); i++)
        {
            if(S[i] == C)
                index.push_back(i);
        }
        
        for(int i=0; i<S.length(); i++)
        {
            smallestDistance = abs(i-index[0]);
            for(int j=1; j<index.size(); j++)
            {
                if(abs(i-index[j]) < smallestDistance)
                    smallestDistance = abs(i-index[j]);
            }
            result.push_back(smallestDistance);
        }
        return result;
    }
};
