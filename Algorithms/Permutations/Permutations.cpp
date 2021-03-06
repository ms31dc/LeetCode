class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        
        do
        {
            for(int i=0; i<nums.size(); i++)
            {
                temp.push_back(nums[i]);
            }
            result.push_back(temp);
            temp.clear();
        }while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
