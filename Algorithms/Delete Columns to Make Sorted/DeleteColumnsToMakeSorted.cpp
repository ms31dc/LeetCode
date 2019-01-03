class Solution
{
public:
    int minDeletionSize(vector<string>& A)
    {
        int result = 0;
        int length = A[0].size();
        for(int i=0; i<length; i++)
        {
            for(int j=1; j<A.size(); j++)
            {
                if(A[j-1][i] > A[j][i])
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};
