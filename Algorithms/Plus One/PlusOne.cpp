class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        long count=0;
        bool flag = false;
        if(digits[digits.size()-1] == 9)
        {
            for(int i=0; i<digits.size(); i++)
            {
                if(digits[i] == 9)
                    count++;
                else
                    break;
            }
            
            if(count == digits.size())
            {
                digits[0] = 1;
                for(int i=1; i<digits.size(); i++)
                {
                    digits[i] = 0;
                }
                digits.push_back(0);
            }
            else
            {
                for(int i=digits.size()-1; i>=0; i--)
                {
                    if(digits[i] == 9)
                        digits[i] = 0;
                    else
                    {
                        digits[i] = digits[i] + 1;
                        break;
                    }
                }
            }
        }
        else
        {
            digits[digits.size()-1] = digits[digits.size()-1] + 1;
        }
        return digits;
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
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
