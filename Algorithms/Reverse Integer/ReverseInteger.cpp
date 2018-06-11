class Solution
{
public:
    int reverse(int x)
    {
        int result=0;
        bool flag = false;
        
        if(x < 0)
        {
            flag = true;
            x = abs(x);
        }
        
        while(x > 0)
        {
            result = result*10;
            int temp = x % 10;
            result = result + temp;
            x = x / 10;
            if((result > 214748364) && (x > 0))
                return 0;
        }
        
        if(flag)
            result = result * (-1);
        
        return result;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
