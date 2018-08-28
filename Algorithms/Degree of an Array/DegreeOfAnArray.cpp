class Solution 
{
public:
    int findShortestSubArrayLength(vector<int>& nums, int number)
    {
        bool start = true, end = true;
        int i = 0, j = nums.size()-1;
        while(start || end)
        {
            if(nums[i] != number)
            {
                i++;
            }
            else
            {
                start = false;
            }
            
            if(nums[j] != number)
            {
                j--;
            }
            else
            {
                end = false;
            }
        }      
        return (j-i+1);
    }
    
    int findShortestSubArray(vector<int>& nums) 
    {
        vector<int> result = nums;
        sort(result.begin(), result.end());
        int i, count=1, frequency=0, output=INT_MAX, newOutput=0;
        for(i=1; i<result.size(); i++)
        {
            if(result[i] == result[i-1])
            {
                count++;
            }
            else
            {
                if(count >= frequency)
                {                    
                    newOutput = findShortestSubArrayLength(nums, result[i-1]);
                    if(count > frequency)
                    {
                        output = newOutput;
                    }
                    else if((newOutput < output) && (count == frequency))
                    {
                        output = newOutput;
                    }
                    frequency = count;            
                }
                count = 1;
            }
        }
        if(count >= frequency)
        {
            newOutput = findShortestSubArrayLength(nums, result[i-1]);
            if(count > frequency)
            {
                output = newOutput;
            }
            else if((newOutput < output) && (count == frequency))
            {
                output = newOutput;
            }
            frequency = count;            
        }
        return output;
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
        
        int ret = Solution().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
