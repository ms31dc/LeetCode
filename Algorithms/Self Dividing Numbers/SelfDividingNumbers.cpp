class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        int count = 0, num = 0;
        vector<int> result;
        for(int i = left; i <= right; i++)
        {
            num = i;
            while(num > 0)
            {
                if(num % 10 != 0)
                {
                    if((i % (num % 10)) == 0)
                    {
                        num /= 10;
                    }
                    else
                    {
                        count++;
                        break;
                    }
                }
                else
                {
                    count++;
                    break;
                }
            }
            if(!count)
                result.push_back(i);
            count=0;
        }
        return result;
    }
};

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
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);
        
        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
