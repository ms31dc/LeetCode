class Solution 
{
public:
    int largestPerimeter(vector<int>& A) 
    {
        sort(A.rbegin(), A.rend());
        int length = A.size()-2;
        for(int i=0; i<length; i++)
        {
            int x = A[i];
            int y = A[i+1];
            int z = A[i+2];
            if(((x + y) > z) &&
               ((x + z) > y) &&
               ((y + z) > x))
            {
                return (x + y + z);
            }
        }
        return 0;
    }
};
