class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> result;
        for(int i=0; i<=num; i++)
        {
            int temp = i;
            int count=0;
            while(temp > 0)
            {
                if(temp%2 != 0)
                    count++;
                temp = temp/2;
            }
            result.push_back(count);
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
        int num = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
