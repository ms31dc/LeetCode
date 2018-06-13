class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int length = (nums.size() / 2), count = 1;
        sort(nums.begin(), nums.end());
        if(nums.size() > 3)
        {            
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i-1] == nums[i])
                {
                    count++;
                    if(count > length)
                        return nums[i];
                }
                else
                {
                    count++;
                    if(count <= length)
                        count = 1;
                    else
                        return nums[i];
                }
            }
        }
        else
        {
            if(nums.size() == 3)
            {
                if(nums[0] == nums[1])
                    return nums[0];
                else
                    return nums[1];
            }
            else if(nums.size() < 3)
                return nums[0];
        }
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) 
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
    {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().majorityElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
