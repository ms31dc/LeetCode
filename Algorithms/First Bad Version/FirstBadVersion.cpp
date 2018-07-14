// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int low=1, high=n, version;
        while(low < high)
        {
            version = low + (high - low)/2;
            if(isBadVersion(version))
            {
                high = version;
            }
            else
            {
                low = version+1;            
            }
        }
        return low;
    }
};
