class Solution
{
public:
    int mySqrt(int x)
    {
        long result=0;
        while(result < x)
        {
            if((result*result) > x)
            {
                break;
            }
            else
            {
                result++;
            }
        }
        if(x == 0)
            return 0;
        if(x >= 1 && x <=3)
            return 1;
        return (result-1);
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
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
