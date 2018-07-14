class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int next;
        vector<int>::iterator it;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++)
        {
            next = target - numbers[i];
            it = find(numbers.begin()+i+1, numbers.end(), next);
            if(it != numbers.end())
            {
                result.push_back(i+1);
                result.push_back(it - numbers.begin() + 1);
            }
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

int stringToInteger(string input) 
{
    return stoi(input);
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
        vector<int> numbers = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(numbers, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
