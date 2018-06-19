class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int result = 1;
        
        if(num <= 1)
            return false;
        
        for(int i=2; i*i<=num; i++)
        {
            if(num%i == 0)
            {
                result = result + i + (num / i);
                if(result > num)
                    return false;
            }
        }
        
        return (result == num);
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int num = stringToInteger(line);
        
        bool ret = Solution().checkPerfectNumber(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
