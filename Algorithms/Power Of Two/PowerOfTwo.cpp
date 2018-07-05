class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        bool flag = false;
        if(n < 1)
        {
            return false;
        }
        if(n == 1)
        {
            return true;
        }
        else if(n > 1)
        {
            while(n > 1)
            {
                if(n%2 != 0)
                {
                    flag = true;
                    break;
                }
                n = n/2;
            }
        }
        if(flag)
        {
            return false;
        }
        return true;
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
        int n = stringToInteger(line);
        
        bool ret = Solution().isPowerOfTwo(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
