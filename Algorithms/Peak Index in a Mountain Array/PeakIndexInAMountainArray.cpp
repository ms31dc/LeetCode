class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        vector<int> temp = A;
        sort(temp.begin(), temp.end());
        int element = temp[temp.size()-1];
        for(int i=0; i<A.size(); i++)
        {
            if(A[i] == element)
                return i;
        }
        return -1;
    }
};
