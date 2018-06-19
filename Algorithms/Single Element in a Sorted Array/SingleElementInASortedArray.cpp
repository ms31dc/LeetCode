class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int result = 0;
        bool found = false;
        for(int i=1; i<nums.size(); i=i+2)
        {
            if(nums[i-1]^nums[i])
            {
                result = nums[i-1];
                found = true;
                break;
            }
        }
        if(found)
            return result;
        return(nums[nums.size()-1]);
            
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
        
        int ret = Solution().singleNonDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
