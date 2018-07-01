class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int result;
        bool flag = true;
        sort(nums.begin(), nums.end());
        if(nums.size() > 4)
        {
            for(int i=1; i<nums.size()-4; i=i+3)
            {
                if((nums[i] == nums[i-1]) && (nums[i] == nums[i+1]))
                {
                    //Continue
                }
                else
                {
                    if((nums[i] != nums[i-1]) && (nums[i] == nums[i+1]))
                    {
                        result = nums[i-1];
                    }
                    else
                    {
                        result = nums[i+1];
                    }
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                result = nums[nums.size() - 1];
            }
        }
        else if(nums.size() == 4)
        {
            if(nums[0] != nums[1])
            {
                result = nums[0];
            }
            else
            {
                result = nums[3];
            }
        }
        else if(nums.size() == 1)
        {
            return nums[0];
        }
        return result;
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
        
        int ret = Solution().singleNumber(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
