class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& nums) 
    {
        vector<int> numsDesc = nums;
        vector<string> result;
        sort(numsDesc.begin(), numsDesc.end(), greater<int>());
        
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>::iterator it;
            it = find(numsDesc.begin(), numsDesc.end(), nums[i]);
            int index = distance(numsDesc.begin(), it) + 1;
            if(index == 1)
            {
                result.push_back("Gold Medal");
            }
            else if(index == 2)
            {
                result.push_back("Silver Medal");
            }
            else if(index == 3)
            {
                result.push_back("Bronze Medal");
            }
            else
            {
                result.push_back(to_string(index));
            }
        }
        return result;
    }
};

