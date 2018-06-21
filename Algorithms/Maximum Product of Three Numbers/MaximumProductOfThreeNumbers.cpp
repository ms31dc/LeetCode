class Solution 
{
public:
    int maximumProduct(vector<int>& nums)
    {
        bool zero = false;
        int count=0, negative=0;
        std::sort(nums.begin(), nums.end(), std::greater<>());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                zero = true;
            if(nums[i] > 0)
                count++;
            if(nums[i] < 0)
                negative++;
        }
        if(count > 2)
        {
            if(negative > 1)
            {
                int temp1 = nums[0]*nums[1]*nums[2];
                int temp2 = nums[0]*nums[nums.size()-2]*nums[nums.size()-1];
                if(temp1 > temp2)
                    return temp1;
                else
                    return temp2;   
            }
            else
            {
                return (nums[0]*nums[1]*nums[2]);
            }
        }
        else if(count == 2)
            return (nums[0]*nums[nums.size()-2]*nums[nums.size()-1]);
        else if(count == 1)
            return (nums[0]*nums[nums.size()-2]*nums[nums.size()-1]);
        else if(count == 0 && zero)
            return 0;
        else if(count == 0 && !zero)
            return (nums[0]*nums[1]*nums[2]);
        return 0;
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
        
        int ret = Solution().maximumProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
