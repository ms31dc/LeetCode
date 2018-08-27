class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int i, repeat, missing;
        bool notFound = true;
        
        for(i=1; i<nums.size(); i++)
        {
            if(nums[i-1] == nums[i])
            {
                repeat = nums[i];
                nums.erase(nums.begin() + i);
                break;
            }
        }

        for(i=0; i<nums.size(); i++)
        {
            if(nums[i] != i+1)
            {
                notFound = false;
                missing = i+1;
                break;
            }
        }
        
        if(notFound)
        {
            missing = i+1;
        }
        
        result.push_back(repeat);
        result.push_back(missing);
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

string integerVectorToString(vector<int> list, int length = -1) 
{
    if (length == -1) 
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution().findErrorNums(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
